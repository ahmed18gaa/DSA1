const form = document.getElementById('calc-form');
const operation = document.getElementById('operation');
const secondLabel = document.getElementById('second-label');
const resetButton = document.getElementById('reset');

const outYears = document.getElementById('out-years');
const outMonths = document.getElementById('out-months');
const outDays = document.getElementById('out-days');
const outSign = document.getElementById('out-sign');
const resultText = document.getElementById('result-text');
const resultTotal = document.getElementById('result-total');

const durationOps = new Set(['add-duration', 'sub-duration']);

function toNumber(value) {
  const parsed = Number.parseInt(value, 10);
  return Number.isFinite(parsed) ? parsed : 0;
}

function toTotalDays(years, months, days) {
  return (years * 360) + (months * 30) + days;
}

function fromTotalDays(totalDays) {
  const sign = totalDays < 0 ? '-' : '';
  const abs = Math.abs(totalDays);
  const years = Math.floor(abs / 360);
  const rem = abs % 360;
  const months = Math.floor(rem / 30);
  const days = rem % 30;
  return { sign, years, months, days, totalDays };
}

function updateSecondLabel() {
  const label = durationOps.has(operation.value)
    ? secondLabel.dataset.durationLabel
    : secondLabel.dataset.dateLabel;
  secondLabel.textContent = label;
}

function renderResult(result) {
  const signIndicator = result.sign === '-' ? '-' : '+';
  const sep = resultText.dataset.separator || ',';
  const yearUnit = resultText.dataset.yearUnit || 'year';
  const monthUnit = resultText.dataset.monthUnit || 'month';
  const dayUnit = resultText.dataset.dayUnit || 'day';
  const totalPrefix = resultTotal.dataset.prefix || 'Total days:';

  outSign.textContent = signIndicator;
  outYears.textContent = `${result.years}`;
  outMonths.textContent = `${result.months}`;
  outDays.textContent = `${result.days}`;

  resultText.textContent = `${result.years} ${yearUnit}${sep} ${result.months} ${monthUnit}${sep} ${result.days} ${dayUnit}`;
  resultTotal.textContent = `${totalPrefix} ${result.totalDays}`;
}

function calculate() {
  const y1 = toNumber(document.getElementById('y1').value);
  const m1 = toNumber(document.getElementById('m1').value);
  const d1 = toNumber(document.getElementById('d1').value);

  const y2 = toNumber(document.getElementById('y2').value);
  const m2 = toNumber(document.getElementById('m2').value);
  const d2 = toNumber(document.getElementById('d2').value);

  const total1 = toTotalDays(y1, m1, d1);
  const total2 = toTotalDays(y2, m2, d2);

  const isAdd = operation.value.startsWith('add');
  const resultDays = isAdd ? total1 + total2 : total1 - total2;

  renderResult(fromTotalDays(resultDays));
}

function resetAll() {
  document.getElementById('y1').value = 0;
  document.getElementById('m1').value = 0;
  document.getElementById('d1').value = 0;
  document.getElementById('y2').value = 0;
  document.getElementById('m2').value = 0;
  document.getElementById('d2').value = 0;
  operation.value = 'add-date';
  updateSecondLabel();
  renderResult(fromTotalDays(0));
}

operation.addEventListener('change', updateSecondLabel);
form.addEventListener('submit', (event) => {
  event.preventDefault();
  calculate();
});
resetButton.addEventListener('click', resetAll);

updateSecondLabel();
renderResult(fromTotalDays(0));
