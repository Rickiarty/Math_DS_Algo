var lock = true;
var cancellation = true;
var stopped = true;
var n = 1;
var width = n;
var height = n;
var grid = [[false]];
//const columnNames = [ "A", "B", "C", "D", "E", "F", "G", "H" ];
const period = 2000;

function cancel_resume() {
    cancellation = !cancellation;
    if (cancellation) {
        document.getElementById("btn2").innerText = " start new ";
    } else {
        document.getElementById("btn2").innerText = "  cancel   ";
    }
}

function toggleSwitch() {
    lock = !lock;
    if (lock) {
        document.getElementById("btn1").innerText = "  RUN  ";
        if (!stopped) {
            document.getElementById("label1").textContent = "[ status: PAUSED ]";
        }
    } else {
        document.getElementById("btn1").innerText = " PAUSE ";
        if (!stopped) {
            document.getElementById("label1").textContent = "[ status: RUNNING ]";
        }
    }
}

function init() {
    cancellation = false;
    document.getElementById("btn2").innerText = "  cancel   ";
    lock = true;
    document.getElementById("btn1").innerText = "  RUN  ";
    document.getElementById("textarea1").value = "";
    var nStr = document.getElementById("textbox1").value;
    n = parseInt(nStr);
    width = n;
    height = n;
    grid = Array(n)
    .fill()
    .map(() => Array(n).fill(false));
    stopped = false;
    document.getElementById("label1").textContent = "[ status: PAUSED ]";
    console.table(grid); // print on console of web-browser 
    renderGridView(); // render on webpage 
}

function printGridStatusInTextArea() {
    var str = "";
    for (var y = 0; y < height; y += 1) {
        for (var x = 0; x < width; x += 1) {
            if (grid[y][x]) {
                str += "Q";
            } else {
                str += ".";
            }
        }
        str += "\n";
    }
    str += "------------\n";
    document.getElementById("textarea1").value += str;
}

function renderGridView() {
    // 渲染(render)棋盤 
    var htmlStr = "";
    htmlStr += "<tr>";
    htmlStr += "<th>\\</th>";
    for (var x = 0; x < width; x += 1) {
        htmlStr += "<th>" + (x + 1) + "</th>";
    }
    htmlStr += "</tr>";
    for (var y = 0; y < height; y += 1) {
        htmlStr += "<tr>";
        htmlStr += "<th>" + (height - y) + "</th>";
        for (var x = 0; x < width; x += 1) {
            if (grid[y][x]) {
                htmlStr += "<td>※</td>";
            } else {
                if ((height - y) % 2 == 0) {
                    if (x % 2 == 0) {
                        htmlStr += "<td>□</td>";
                    } else {
                        htmlStr += "<td>■</td>";
                    }
                } else {
                    if (x % 2 == 0) {
                        htmlStr += "<td>■</td>";
                    } else {
                        htmlStr += "<td>□</td>";
                    }
                }
            }
        }
        htmlStr += "</tr>";
    }
    document.getElementById("table1").innerHTML = htmlStr;
}

function isValid(x, y) {
    for (var i = 1; i < width; i += 1) {
        if (y - i >= 0 && y - i < height && x - i >= 0 && x - i < width) {
            if (grid[y - i][x - i]) {
                return false;
            }
        }
        if (y - i >= 0 && y - i < height && x + i >= 0 && x + i < width) {
            if (grid[y - i][x + i]) {
                return false;
            }
        }
        if (y - i >= 0 && y - i < height) {
            if (grid[y - i][x]) {
                return false;
            }
        }
    }
    return true;
}

async function solQueens(y) {
    var sum = 0;
    for (var x = 0; x < width; x += 1) {
        if (cancellation) {
            return sum;
        }
        while (lock) {
            if (cancellation) {
                return sum;
            }
            await new Promise(r => setTimeout(r, period));
        }
        if (isValid(x, y)) {
            grid[y][x] = true;
            console.table(grid); // print on console of web-browser 
            renderGridView(); // render on webpage 
            if (y == height - 1) {
                sum += 1;
                printGridStatusInTextArea();
            }
            else {
                sum += await solQueens(y + 1);
            }
            grid[y][x] = false;
            console.table(grid); // print on console of web-browser 
            renderGridView(); // render on webpage 
        }
    }
    return sum;
}

async function SolveQueens() {
    return await solQueens(0);
}

async function perform() {
    document.getElementById("textbox1").value = "8";
    document.getElementById("label1").textContent = "[ status: STOPPED ]";
    while (true) {
        while (cancellation) {
            await new Promise(r => setTimeout(r, period));
        }
        init();
        var total = await SolveQueens();
        stopped = true;
        document.getElementById("label1").textContent = "[ status: STOPPED ]";
        console.log("When n = " + n + ", \nnumber of solutions = " + total.toString());
        document.getElementById("textbox2").value = total.toString();
        cancellation = true;
        document.getElementById("btn2").innerText = " start new ";
        lock = true;
    }
}

perform();
