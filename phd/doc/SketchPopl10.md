# Utilize Sketch to give specification and synthesize

We can encode the input specification in Sketch. For example, we can write the function that calculating **XOR** result of all bits in the input vector as below in Sketch ("^" means XOR between two bits in Sketch)
```c
bit[MAX] allXOR (int n, bit[MAX] in) {
    assume n<MAX;
    assume n>2;
    bit t = in[0] ^ in[1];
    for (int i=2; i < n; i++){
        t = in[i] ^ t;
    }
    in[0] = t;
    return in;
}
```
**in** is the input bit vector. **n** is the input size parameter referring to how many bits are needed. It suggests this function uses bits in[0],in[1],...,in[n-1]. **MAX** is a prespecified maximum length that we can support, and we can assume **n<MAX**. **MAX** can be a large enough integer. The function defines a bit variable *t* to store the expected result and finally put it in **in[0]**. 

Notice the two assignment statements of bit variables in the original program
```c
bit t = in[0] ^ in[1];
in[0] = t;
```
are impossible to implement in the quantum case. So we can restrict Sketch to synthesize a new equivalent program in which the statements of bits are all in the form
```c
a = a ^ b
a = a | b
a = a & b
a = ! a
...
```
where **a,b** are bits. These operations can be implemented by Toffoli gate in quantum circuit. The result program from Sketch is
```c
bit[MAX] allXORSketch (int n, bit[MAX] in)  implementsallXOR
{
  assume (n < MAX);
  assume (n > 2);
  int i = 1;
  while(i < n)
  {
    in[0] = (in[0]) ^ (in[i]);
    i = i + 1;
  }
  return in;
}
```
The only operation of bit variables is in **a=a^b** form. Then we just need to replace the expression **a=a^b** with Toffoli(b,1,a), replace all bit variables with qubit, remove the **return** and get the result program
```c
void allXORSketch (int n, qubit[MAX] in)
{
  assume (n < MAX);
  assume (n > 2);
  int i = 1;
  while(i < n)
  {
    Toffoli(in[i], 1, in[0]);
    i = i + 1;
  }
}

```