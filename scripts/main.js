import { hello } from "./a.js";
const mod = await import("./b.js");
import * as c from "./c.js";
mod.hijack();
mod.Hello();
hello();

console.log(c.add(1, 2)); // 3
console.log(c.sub(5, 3)); // 2
console.log(c.PI, 2.718); // 3.14159
console.warn("FBI Warning");
console.info("系统日志");
console.error("发现异常");
console.success("操作成功");

const obj = { a: 1, b: 2 };
const str = JSON.stringify(obj);
console.log(str); // {"a":1,"b":2}

const x = new X(true);
console.log(x.b, x.str, x.c);
//let y = new Y(100, false);
//console.log(y.b, y.prop, Y.ext_fun(123));
//let y = makeY(100, false);
//console.log(y.b, y.prop, Y.ext_fun(123));

let arr0 = getArr();
console.log(arr0[0].prop, arr0[1].prop);
//arr0 = null;
let arr = [];
for (let i = 0; i < 100000; i++) {
  arr.push({ name: "jack" });
}
//let z = makeZ(123);
//console.log(z.z);

//addPaintListener(OnPaint1);

const OnPaint = () => {
  console.log("JS: Paint event fired!");
};

//addPaintListener(OnPaint);

function OnPaint1() {
  print("JS: Paint1 event fired!");
}
