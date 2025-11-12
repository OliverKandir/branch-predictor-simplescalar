# Branch Predictor Performance Evaluation using SimpleScalar

Repository for our ACA project evaluating branch predictors in SimpleScalar.

This work connects to modern CPU–LLM interaction: large language models (LLMs) depend heavily on efficient processor microarchitecture. Their high token-throughput demand stresses front-end performance, and branch prediction efficiency becomes critical when running transformer inference kernels on general-purpose CPUs. By studying classical predictors (bimodal, 2-level, comb, etc.) in a controlled SimpleScalar environment, we outline how prediction accuracy and CPI/IPC balance impact real-world workloads, including LLM runtimes that rely on dense linear algebra and control-heavy host code.

<blockquote>
<p><b>Note:</b> Both <code>bpred_taken</code> and <code>bpred_nottaken</code> are <i>static branch predictors</i> — they make fixed predictions for every branch (always “taken” or “not taken”).</p>
<p>In our experiments, both predictors reported nearly identical <code>bpred_dir_rate</code> values because the benchmark programs executed within <b>SimpleScalar</b> exhibited a balanced mix of taken and not-taken branches.</p>
<p style="margin-left: 2em;">Since each run uses the same instruction stream and branch distribution, the ratio of correctly predicted branches for both static strategies becomes numerically similar.</p>
<p style="margin-left: 2em;">Additionally, <b>SimpleScalar</b> reports results rounded to four decimal places, which can make minor differences appear identical.</p>
</blockquote>

