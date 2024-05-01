let display = document.getElementById('display');
let expression = '';

function appendToDisplay(value) {
    expression += value;
    display.value = expression;
}

function clearDisplay() {
    expression = '';
    display.value = '';
}

function operate(operator) {
    expression += ` ${operator} `;
    display.value = expression;
}

function calculate() {
    try {
        let result = eval(expression);
        display.value = result;
        expression = '';
    } catch (error) {
        display.value = 'Error';
        expression = '';
    }
}
