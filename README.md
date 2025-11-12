# Branch Predictor Performance Evaluation using SimpleScalar

Repository for our ACA project evaluating branch predictors in SimpleScalar.

This work connects to modern CPU–LLM interaction: large language models (LLMs) depend heavily on efficient processor microarchitecture. Their high token-throughput demand stresses front-end performance, and branch prediction efficiency becomes critical when running transformer inference kernels on general-purpose CPUs. By studying classical predictors (bimodal, 2-level, comb, etc.) in a controlled SimpleScalar environment, we outline how prediction accuracy and CPI/IPC balance impact real-world workloads, including LLM runtimes that rely on dense linear algebra and control-heavy host code.

**Note:**  
&nbsp;&nbsp;&nbsp;&nbsp;Both <b>bpred_taken</b> and <b>bpred_nottaken</b> are *static branch predictors* — they make fixed predictions for every branch (always **“taken”** or always **“not taken”**).  
&nbsp;&nbsp;&nbsp;&nbsp;In our experiments, both predictors reported nearly identical <b>bpred_dir_rate</b> values because the benchmark programs executed within **SimpleScalar** exhibited a **balanced mix of taken and not-taken branches**.  
&nbsp;&nbsp;&nbsp;&nbsp;Since each run uses the same instruction stream and branch distribution, the ratio of correctly predicted branches for both static strategies becomes numerically similar.  
&nbsp;&nbsp;&nbsp;&nbsp;Additionally, **SimpleScalar** reports results rounded to four decimal places, which can make minor differences appear identical.


# SimpleScalar Usage — Running Experiments

## Compile C Programs (PISA Target)

$IDIR/bin/sslittle-na-sstrix-gcc -O2 -o <output> <program>.c

Example:
$IDIR/bin/sslittle-na-sstrix-gcc -O2 -o 1 1.c


## Analyze Branch Predictors

$IDIR/simplesim-3.0/sim-outorder -bpred <predictor> <program>

Examples:
$IDIR/simplesim-3.0/sim-outorder -bpred 2lev 1
$IDIR/simplesim-3.0/sim-outorder -bpred bimod 1
$IDIR/simplesim-3.0/sim-outorder -bpred comb 1


## Supported Predictors
taken  
nottaken  
bimod  
2lev  
comb

