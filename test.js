
function getLastNegative(arr) {
    let lastNeg = 0;
    for (i = 0; i < arr.length; i++) {
        if (arr[i] < 0) lastNeg = arr[i];
    }

    return (lastNeg < 0 ? lastNeg : "No elements less than 0");
}

function lastNeg(i) {
    if (i < 0) {
        return i;
    }
}

let arr = [-2, 1, 3, 4, -4, 3, -5, 2];

console.log(getLastNegative(arr));