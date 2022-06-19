https://www.luogu.com.cn/problem/P1045

https://www.luogu.com.cn/problem/P1601

https://www.luogu.com.cn/problem/P1255

https://www.luogu.com.cn/problem/P2142

# 类型

int 4字节  32位 31  $2^{31}-1$

long long 8字节  64位  $2^{63}-1$

# 累乘

```c++
int s=1;
for (int i=1; i<=31; ++i) s*=2;
printf("%d", s);
long long s=1;
```

# 高精度乘法 竖式乘法  高精度乘单精度

> 数据读入，存储，高低位 
>
> char str1[N];  "%s"读入 str1[0]最高位 ====》a数组 数字  高低位

```c++
scanf("%s%d", str1, &b);
l=strlen(str1);  //长度l 0开始编号 l-1 
for (int i=0; i<l; ++i) a[l-i-1]=str1[i]-48; //str1[i]====>a[l-i-]
```

> 乘法竖式

```c++
//乘法  a*b===c
c[0]=0;
for (int i=0; i<l; ++i){
	c[i]+=a[i]*b;   //c[i]=c[i]+a[i]*b;
	c[i+1]=c[i]/10;
	c[i]=c[i]%10;  //c[i]%=10;
}
//处理进位 
++l;
while (c[l-1]>0){
	c[l]=c[l-1]/10;
	c[l-1]%=10;
	++l;
}
while (l>1 and c[l-1]==0) --l;
```

> 输出

```c++
for (int i=l-1; i>=0; --i) printf("%d", c[i]);

int num=0;
for (int i=l-1; i>=0; --i){
	printf("%d", s[i]);
	++num;
	if (num%50==0) printf("\n");
}
```

# 累乘

```c++
初始化s数组s[0]=1 记录长度l=1
memset(s, 0, sizeof s);
s[0]=1;
l=1;
//for (int i=1; i<=n; ++i) s*=b;

for (int i=1; i<=n; ++i) mult(s, l, b); //s数组长度为l，乘以数值b结果再存回s数组，新的长度是l

void mult(int a[N], int &l, int b){
	//a数组长度为l，乘以数值b结果再存回a数组，新的长度是l
	c[0]=0;
	for (int i=0; i<l; ++i){
        c[i]+=a[i]*b;
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
	
    ++l;
    while(c[l-1]>0){
        c[l]=c[l-1]/10;
        c[l-1]%=10;
        ++l;
    }
    while(l>1 and c[l-1]==0) --l;
    
    for (int i=0; i<l; ++i) a[i]=c[i];
}
```

# 计算N!

```c++
scanf("%d", &n);

s=1;
for (int i=1; i<=n; ++i) s*=i;

memset(s, 0, sizeof s);s[0]=1;l=1;
for (int i=1; i<=n; ++i) mult(s, l, i); //s数组长度为l，乘以数值i结果再存回s数组，新的长度是l
```

# 麦森数简版程序

```c++
//没有计算总位数
#include <cstdio>
#include <cstring>
const int N = 550;
int s[N], c[N]; 
int p, l;

void mult(int a[N], int &l, int b){
	//a*b===c===>a
	c[0]=0;
	for (int i=0; i<500; ++i){
		c[i]+=a[i]*b;   //c[i]=c[i]+a[i]*b;
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;  //c[i]%=10;
	}
			
	//c数组  长度l l-1----0 
	for (int i=0; i<500; ++i) a[i]=c[i]; 
	
}

int main(){
	
	scanf("%d", &p);
	
	memset(s, 0, sizeof s); s[0]=1; l=1;
	
	for (int i=1; i<=p; ++i) mult(s, l, 2);

	int num=0;
	for (int i=499; i>=0; --i){
		printf("%d", s[i]);
		++num;
		if (num%50==0) printf("\n");
	}
	
	return 0;
} 
```

# 预习一下对数

- 对数

$$
\begin{align}
& x^y=s  \ \ \ \ a*b=c=====>x底数  y对数  s真数\\
& 已知x，和s求y,y=\log_{x}^{s}  \ \ \ \ a=\frac{c}{b}\\
& 10^3=1000  =====>\log_{10}^{1000}=3\\
& 2^3=8=======>\log_{2}^{8}=3\\
& a*b=10^c=====>c=log_{10}{a*b}\\
& 100*10000=10^6=====>10^2*10^4=10^6 \\
& log_{10}{a*b}====>log_{10}{a}+log_{10}{b} \\
& log_{10}{a/b}====>log_{10}{a}-log_{10}{b} \\
& log_{10}^{a^3}=log_{10}{a*a*a}====>log_{10}{a}+log_{10}{a}+log_{10}{a}=3log_{10}{a}
\end{align}
$$

- 计算x的位数y

$$
y=\lfloor \log_{10}^{x}\rfloor+1
$$

- 计算a\*b的位数y

$$
\begin{align}
y=&\lfloor \log_{10}^{a*b}\rfloor+1\\
&\lfloor \log_{10}^{a}+\log_{10}^{b}\rfloor+1
\end{align}
$$

- 计算N!的位数y

$$
\begin{align}
y=&\lfloor \log_{10}^{N!}\rfloor+1\\
&\lfloor \log_{10}^{1}+...+\log_{10}^{N}\rfloor+1
\end{align}
$$

- 计算$2^p$的位数y

$$
\begin{align}
y=&\lfloor \log_{10}^{2^p}\rfloor+1\\
&\lfloor p*\log_{10}^{2}\rfloor+1
\end{align}
$$

- 换底公式

$$
自然对数：ln(x)===>\log_{e}^{x}===>ln(x)\\
e自然常数2.7 无理数 \\
常用对数：lg(x)===>\log_{10}{x} ===>log10(x)\\
log_{a}^{b}====>\frac{\log_{c}{b}}{\log_{c}{a}}
$$

- p==》二进制的位数

$$
2^y=p===>y=\log_{2}{p}=\frac{\log_{10}{p}}{\log_{10}{2}}
$$

