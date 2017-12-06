var curVal = 0
var memory = 0
var lastOp = ""
var previousOperator = ""
var digits = ""

function isInt(value) {
  return !isNaN(value) &&
         parseInt(Number(value)) === value &&
         !isNaN(parseInt(value, 10));
}

function sFact(num) {
    if (!isInt(num))
        return -1
    if (num < 0)
        return -1
    var rval=1;
    for (var i = 2; i <= num; i++)
        rval = rval * i;
    return rval;
}

Math.tanh = Math.tanh || function(x) {
  if (x === Infinity) {
    return 1;
  } else if (x === -Infinity) {
    return -1;
  } else {
    var y = Math.exp(2 * x);
    return (y - 1) / (y + 1);
  }
}

function disabled(op) {
    if (digits == "" && !((op >= "0" && op <= "9") || op === "."))
        return true
    else if (op === '=' && previousOperator.length != 1)
        return true
    else if (op === "." && digits.toString().search(/\./) != -1) {
        return true
    } else if (op === "√" &&  digits.toString().search(/-/) != -1) {
        return true
    } else {
        return false
    }
}

function digitPressed(op) {
    if (disabled(op))
        return
    if (digits.toString().length >= display.maxDigits)
        return

    if (lastOp.toString().length == 1 && ((lastOp >= "0" && lastOp <= "9") || lastOp == "." || lastOp == "\u03C0") ) {

        if (op === "\u03C0") {
            console.log("check")
            digits = 3.14159265359
            display.displayNumber(Number(digits.toString()))
            lastOp = op
            return
        }

        digits = digits + op.toString()
        display.appendDigit(op.toString())
    } else {
        digits = op
        display.appendDigit(op.toString())
    }
    lastOp = op
}

function operatorPressed(op) {
    console.log(lastOp)
    if (op === '=' && previousOperator === 'x\u207F') {// x^n
        digits = Number(Math.pow(memory, Number(digits.valueOf())))
        display.newLine("x\u207F", Number(digits.valueOf()))
        curVal = 0
        memory = 0
        lastOp = ""
    } else if (op === '=' && previousOperator === "\u207F\u221A") {// "n√"
        var temp = (1 / Number(digits.valueOf()))
        console.log(temp)
        digits = Number(Math.pow(memory, temp))
        console.log(digits)
        display.newLine("\u207F\u221A", Number(digits.valueOf()))
        curVal = 0
        memory = 0
        lastOp = ""
    }
    if (disabled(op))
        return
    lastOp = op


    if (op === "±") {
            digits = Number(digits.valueOf() * -1)
            display.setDigit(display.displayNumber(digits))
            return
        }

    if (previousOperator == "+") {
        digits = Number(digits.valueOf()) + Number(curVal.valueOf())
    } else if (previousOperator == "−") {
        digits = Number(curVal.valueOf()) - Number(digits.valueOf())
    } else if (previousOperator == "×") {
        digits = Number(curVal) * Number(digits.valueOf())
    } else if (previousOperator == "÷") {
        digits = Number(curVal) / Number(digits.valueOf())
    }

    if (op === "+" || op === "−" || op === "×" || op === "÷") {
        previousOperator = op
        curVal = digits.valueOf()
        digits = ""
        display.displayOperator(previousOperator)
        return
    }

    if (op === "=") {
        display.newLine("=", digits.valueOf())
    }



    if (op === "\u00B9\u0337\u2093") { // 1/x
        digits = (1 / Number(digits.valueOf())).toString()
        display.newLine("\u00B9\u0337\u2093", Number(digits.valueOf()))
    } else if (op === "x\u00B2") { // x^2
        digits = (digits.valueOf() * digits.valueOf()).toString()
        display.newLine("x\u00B2", Number(digits.valueOf()))
    } else if (op === "e\u207F") { // e^n
        digits = (Math.exp(Number(digits.valueOf()))).toString()
        console.log("result ", digits);
        display.newLine("e\u207F", Number(digits.valueOf()))
    } else if (op === "x\u00B3") { // "x^3"
        digits = (digits.valueOf() * digits.valueOf() * digits.valueOf()).toString()
        console.log("result ", digits);
        display.newLine("x\u00B3", Number(digits.valueOf()))
    } else if (op === "sh") {
        digits = ((Math.exp(digits.valueOf()) - Math.exp((-1 * digits.valueOf()))) / 2).toString()
        console.log("result ", digits)
        display.newLine("sh", Number(digits.valueOf()))
    } else if (op === "ch") {
        digits = ((Math.exp(digits.valueOf()) + Math.exp((-1 * digits.valueOf()))) / 2).toString()
        console.log("result ", digits)
        display.newLine("ch", Number(digits.valueOf()))
    } else if (op === "sin") {
        digits = (Math.sin(digits.valueOf())).toString()
        display.newLine("sin", Number(digits.valueOf()))
    } else if (op === "cos") {
        digits = (Math.cos(digits.valueOf())).toString()
        display.newLine("cos", Number(digits.valueOf()))
    } else if (op === "th") {
        digits = (Math.tanh(digits.valueOf())).toString()
        display.newLine("th", Number(digits.valueOf()))
    } else if (op === "tan") {
        digits = (Math.tan(digits.valueOf())).toString()
        display.newLine("tan", Number(digits.valueOf()))
    } else if (op === "√") {
        digits = Number(Math.sqrt(digits.valueOf()))
        display.newLine("√", Number(digits.valueOf()))
    } else if (op === "\u00B3\u221A") { // "3√"
        digits = Number(Math.pow(digits.valueOf(), 1/3))
        display.newLine("\u00B3\u221A", Number(digits.valueOf()))
    } else if (op === "n!") {
        var value = sFact(digits.valueOf())
        if (value < 0)
            display.displayNumber("ERROR")
        else
            digits = (sFact(digits.valueOf())).toString()
        display.newLine("n!", Number(digits.valueOf()))
    } else if (op === "ln") {
        digits = Number(Math.log(digits.valueOf()))
        display.newLine("ln", Number(digits.valueOf()))
    } else if (op === "log") {
        digits = Number(Math.log(digits.valueOf())) / Number(Math.log(10))
        display.newLine("log", Number(digits.valueOf()))
    } else if (op === "x\u207F") { // x^n
        display.displayOperator("x\u207F, n=")
        memory = digits.valueOf()
        previousOperator = "x\u207F"
        return
    } else if (op === "\u207F\u221A") { // "n√"
        display.displayOperator("\u207F\u221A, n=")
        memory = digits.valueOf()
        previousOperator = "\u207F\u221A"
        return
    } else if (op === "Off") {
        Qt.quit();
    }

    curVal = 0
    previousOperator = ""
    // Reset the state on 'C' operator or after
    // an error occurred
    if (op === "C" || display.isError) {
        display.clear()
        curVal = 0
        memory = 0
        lastOp = ""
        digits = ""
    }
}
