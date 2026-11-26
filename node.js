let data = JSON.parse(localStorage.getItem('bt_data')) || {
  user: 'New User',
  budget: 0,
  incomes: [],
  expenses: []
};

function setUser() {
  let u = prompt('Enter user name:', data.user);
  let b = parseFloat(prompt('Enter monthly budget ($):', data.budget));
  if (u) data.user = u;
  if (!isNaN(b)) data.budget = b;
  updateUI();
}

function add() {
  let type = document.getElementById('type').value;
  let desc = document.getElementById('desc').value.trim();
  let amt = parseFloat(document.getElementById('amt').value);

  if (!desc || isNaN(amt) || amt <= 0) return alert('Please enter valid details.');

  if (type === 'inc') {
    data.incomes.push({ src: desc, amt });
  } else {
    data.expenses.push({
      id: data.expenses.length + 1,
      amt,
      cat: document.getElementById('cat').value,
      desc,
      month: document.getElementById('month').value
    });
  }

  document.getElementById('desc').value = '';
  document.getElementById('amt').value = '';
  updateUI();
}

function updateUI() {
  let totInc = data.incomes.reduce((sum, i) => sum + i.amt, 0);
  let totExp = data.expenses.reduce((sum, e) => sum + e.amt, 0);
  let left = data.budget - totExp;

  document.getElementById('userBanner').innerText = 'USER: ' + data.user.toUpperCase();
  document.getElementById('bal').innerText = '$' + (totInc - totExp).toFixed(2);
  document.getElementById('inc').innerText = '$' + totInc.toFixed(2);
  document.getElementById('exp').innerText = '$' + totExp.toFixed(2);
  document.getElementById('left').innerText = '$' + left.toFixed(2);

  let st = document.getElementById('status');
  if (data.budget === 0) {
    st.style.borderColor = '#3b82f6';
    st.innerText = 'User: ' + data.user + ' | Budget has not been set! Click "Set User & Budget".';
  } else if (totExp >= data.budget) {
    st.style.borderColor = '#ef4444';
    st.innerText = 'WARNING: Budget limit of $' + data.budget.toFixed(2) + ' reached!';
  } else {
    st.style.borderColor = '#3b82f6';
    st.innerText = 'User: ' + data.user + ' | Within budget. Remaining = $' + left.toFixed(2);
  }

  document.getElementById('bars').innerHTML = ['Housing', 'Food', 'Transport', 'Fun'].map(c => {
    let s = data.expenses.filter(e => e.cat === c).reduce((sum, e) => sum + e.amt, 0);
    let w = Math.min(100, (s / (data.budget || 1)) * 100);
    return `<div style="display:flex;justify-content:space-between;font-size:13px"><span>${c}</span><span>$${s.toFixed(2)}</span></div>
            <div class="bar"><div class="fill" style="width:${w}%"></div></div>`;
  }).join('');

  let q = document.getElementById('find').value.toLowerCase();
  let rows = [
    ...data.expenses.filter(e => e.cat.toLowerCase().includes(q) || e.desc.toLowerCase().includes(q) || e.month.toLowerCase().includes(q))
      .map(e => `<div class="row"><span>${e.desc} (${e.month})</span><span style="color:#3b82f6">${e.cat}</span><span>-$${e.amt.toFixed(2)}</span></div>`),
    ...data.incomes.filter(i => i.src.toLowerCase().includes(q))
      .map(i => `<div class="row"><span>${i.src}</span><span style="color:#8294b0">Income</span><span style="color:#22c55e">+$${i.amt.toFixed(2)}</span></div>`)
  ];
  document.getElementById('list').innerHTML = rows.join('') || '<div class="lbl">No entries yet.</div>';

  drawChart();
}

function drawChart() {
  let canvas = document.getElementById('trendChart');
  let ctx = canvas.getContext('2d');
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  ctx.strokeStyle = '#1b273d';
  ctx.lineWidth = 1;
  for (let y = 30; y <= 150; y += 40) {
    ctx.beginPath(); ctx.moveTo(10, y); ctx.lineTo(390, y); ctx.stroke();
  }

  let pts = data.expenses.length ? data.expenses.map(e => e.amt) : [0, 0];
  if (pts.length === 1) pts = [0, pts[0]];
  let maxVal = Math.max(...pts, 100);

  ctx.beginPath();
  ctx.strokeStyle = '#00e5ff';
  ctx.lineWidth = 3;
  ctx.shadowColor = '#00e5ff';
  ctx.shadowBlur = 10;

  pts.forEach((val, idx) => {
    let x = 15 + (idx / (pts.length - 1)) * 370;
    let y = 150 - (val / maxVal) * 120;
    if (idx === 0) ctx.moveTo(x, y);
    else ctx.lineTo(x, y);
  });
  ctx.stroke();
  ctx.shadowBlur = 0;
}

function save() {
  localStorage.setItem('bt_data', JSON.stringify(data));
  alert('Data saved successfully!');
}

function resetAll() {
  if (confirm('Clear all saved data and start fresh?')) {
    localStorage.removeItem('bt_data');
    location.reload();
  }
}

function report() {
  let totInc = data.incomes.reduce((sum, x) => sum + x.amt, 0);
  let totExp = data.expenses.reduce((sum, x) => sum + x.amt, 0);
  let balance = totInc - totExp;

  let text = `----- FINANCIAL SUMMARY -----\n`;
  text += `User: ${data.user}\n\n`;
  text += `Income Sources:\n`;
  if (data.incomes.length === 0) text += ` - None\n`;
  data.incomes.forEach(i => { text += ` - ${i.src}: $${i.amt.toFixed(2)}\n`; });

  text += `\nExpenses:\n`;
  if (data.expenses.length === 0) text += ` - None\n`;
  data.expenses.forEach(e => { text += ` - [ID:${e.id}] ${e.desc} (${e.category} - ${e.month}): $${e.amt.toFixed(2)}\n`; });

  text += `\nTotal Income: $${totInc.toFixed(2)}\n`;
  text += `Total Expenses: $${totExp.toFixed(2)}\n`;
  text += `Monthly Budget: $${data.budget.toFixed(2)}\n`;
  text += `Balance: $${balance.toFixed(2)}\n`;
  text += `--------------------------------------\n`;

  let blob = new Blob([text], { type: 'text/plain' });
  let link = document.createElement('a');
  link.href = URL.createObjectURL(blob);
  link.download = 'Budget_Tracker_Report.txt';
  link.click();
}


updateUI();
