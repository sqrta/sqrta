# Experiment_report
## The translation rule:
We suggest that at the begining all of the qubits are |0> state, and because the qubit in |0> state is much more stable than qubit in **Superposition**, we can postpone the operation that change the qubits into **Superposition**.<br>
When there is an operation _A_ like:<br>

	Op q1,q2,...,qn
Op is a kind of quantum operation such as **Hadamard** operation or **CNOT** operation, and q1,q2...qn are qubits. If this instruction is where some of qubits in q1,q2...qn first appear in the code,such as qi, we can postpone this instruction and change qi into **Superposition** later. We define _B_ is a quantum instruction executed later than _A_ (maybe several instructions later) and it is the first time one of qubits in {q1,q2...qn} appear again after _A_, then we can move _A_ just before _B_.

## Example and Experiment
Let's think about this quantum program in OpenQASM
```c
include "qelib1.inc";

qreg a[2];              //1
qreg b;                 //2
creg c[3];              //3

h a;                    //4
measure a[0]->c[0];     //5
cx a[1],b;              //6
measure a[1]->c[1];     //7
measure b->c[2];        //8
```
We concentrate on qubits a[1] and b, and their measure result in register c[1,2]. We apply a **Hadamard** operation on a[1] and change it into a **Bell State**. Then we use a[1] as control qubit to apply a **CNOT** operation on qubits a[1] and b[0]. Now the state of a[1] and b[0] should be identical, both |1> or both |0>. So the theoretical result of c[1,2] is 50% percent of [00] and 50% of [11]. <br>

We know that a qubit operation is not always correct, so in the experiment we will find sometimes the result of c[1,2] is [01] or [10]. We suggest the percent of state [01] or [10] is this circuit's error rate. We run this circuit for 5000 times and we get the result.<br>

  | Measure result | Percent(%) |
  | :------------: | :--------: |
  | 00             | 46.37%     |
  | 01             | 6.30%      |
  | 10             | 7.77%      |
  | 11             | 39.83%     |

We can get the error rate is  6.30%+7.77%=14.07%<br>
If we check the code carefully, we will find that the qubit a[1] go through **Hadamard** operation and become **Superposition**in line 4, and it remain superposed for a long time.(The measure operation cost lots of time) This will increase the error rate because **Superposition** is much more unstable than |0> state.
if we adjust the code and postpone the **Hadamard** operation of a[1] after first measurent, the error rate will decrease.
```c
include "qelib1.inc";

qreg a[2];              //1
qreg b;                 //2
creg c[3];              //3

h a[0];                 //4
measure a[0]->c[0];     //5
h a[1];                 //6
cx a[1],b;              //7
measure a[1]->c[1];     //8
measure b->c[2];        //9
```
We also test for 5000 times, and the measure result is

  | Measure result | Percent(%) |
  | :------------: | :--------: |
  | 00             | 46.93%     |
  | 01             | 6.13%      |
  | 10             | 6.41%      |
  | 11             | 40.53%     |

The error rate is 6.13%+6.41%=12.54%, we cut off 11% of the error rate.<br>
