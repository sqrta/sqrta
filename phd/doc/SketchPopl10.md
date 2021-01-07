# Utilize Sketch to synthesize

We can encode the input specification in Sketch. For example, the function that calculating *XOR* result of all bits in the vector can be written as below in sketch
```c
bit[MAX] allXOR (int n, bit[MAX] in) {
    int i=2;
    assume n<MAX;
    assume n>3;
    bit t=in[0] ^ in[1];
    for (; i<n; i++){
        t = in[i] ^ t;
    }
    in[0] = t;
    return in;
}
```
*in* is the input bit vector. *n* is the input size parameter suggesting how much bits are needed.  *MAX* is a prespecified maximum length that we can support and we can assume *n<MAX*. *MAX* can be a larger enough integer. The function define a bit variable *t* to store the expect result and put it in *in[0]*. The operator *^* calculate the *XOR* value of two bits.

Notice the two expressions on bit variables in the original program
```c
bit t=in[0] ^ in[1];
in[0] = t;
```
are impossible to implement in quantum case. So we can restrict Sketch to synthesize a new equivalent program that only containing the expression like
```c
a = a ^ b
```
where *a,b* are bits. This operation can be implemented by Toffoli gate in quantum circuit. The result program from Sketch is
```c
bit[MAX] allXORSketch (int n, bit[MAX] in)  implementsallXOR
{
  assume (n < MAX);
  assume (n > 3);
  int i = 1;
  while(i < n)
  {
    in[0] = (in[0]) ^ (in[i]);
    i = i + 1;
  }
  return in;
}
```
The only operation on bit variables is in *a=a^b* form. Then we just need to replace the expression *a=a^b* with Toffoli(b,1,a), replace all bit variables with qubit, remove the *return* and get the result program
```c
void allXORSketch (int n, qubit[MAX] in)
{
  assume (n < MAX);
  assume (n > 3);
  int i = 1;
  while(i < n)
  {
    Toffoli(in[i], 1, in[0]);
    i = i + 1;
  }
}

```