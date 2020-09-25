function permute(a, i, n) {
    let j;
    if (i === n) {
        console.log(a);
    }
    else {
        for (j = i; j <= n; j++) {
            swap(a, i, j);
            permute(a, i+1, n);
            swap(a, i, j);
        }
    }
}

function swap(a, i, j) {
    let temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

let count = 0;

function perm(arr, i, n, k) {
    if (i === n) {
        console.log(arr);
        count++;
    }
    else {
        for (let j = 0; j < k; j++) {
            arr[i] = j;
            perm(arr, i+1, n, k);
            arr[i] = j;
        }
    }
}

// let arr = ["A", "B", "C"];
// permute(arr, 0, 2);
let arr = [0, 0, 0, 0, 0];
perm(arr, 0, 5, 3);
console.log(count);