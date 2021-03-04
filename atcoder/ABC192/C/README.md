# ABC192-C

```
~/w/c/a/A/C ❯❯❯ gcc -std=c11 -o ./dist/main.out ./src/main.c && ./dist/main.out                                                                       ✘ 145
314 2
n: 314
n%10: 4
n/10: 31
n: 31

n: 31
n%10: 1
n/10: 3
n: 3

n: 3
n%10: 3
n/10: 0
n: 0

n: 297
n%10: 7
n/10: 29
n: 29

n: 29
n%10: 9
n/10: 2
n: 2

n: 2
n%10: 2
n/10: 0
n: 0

```

## 1回目

$334mod10=4$

$e.g. 33×10+4$

```c
c[4]+=1;
```

$\lfloor \frac{334} {10} \rfloor=33$

$c_4:1$

## 2回目

$33mod10=3$

$e.g. 3×10+3$

```c
c[3]+=1
```

$\lfloor \frac{33} {10} \rfloor=3$

$c_3:1$

## 3回目

$3mod10=3$

$f.g. 0×10+3$

```c
c[3]+=1
```

$\lfloor \frac{3} {10} \rfloor=0$

$c_3:2$

## i:9-0 で $i=4$ の時

### j: 0-0(c[4]==1) で $j=0$ の時

$g_1=0×10+4$ (`g1=g1*10+i`)
$ =4$

## i:9-0 で $i=3$ の時

### j: 0-1(c[3]==2) で $j=0$ の時

$g_1=4×10+3$
$ =43$

### j: 0-1(c[3]==2) で $j=1$ の時

$g_1=43×10+3$
$ =433$

## i:0-9 で $i=3$ の時

### j: 0-1(c[3]==2) で $j=0$ の時

$g_2=0×10+3$
$ =3$

### j: 0-1(c[3]==2) で $j=1$ の時

$g_2=3×10+3$
$ =33$

## i:0-9 で $i=4$ の時

### j: 0-0(c[4]==1) で $j=0$ の時

$g_2=33×10+4$
$ =334$

## $f(x)=g1(x)-g2(x)$

$f(334)=g_1-g_2=433-334$
$ =99$