# Branch Predictor Performance Evaluation using SimpleScalar

Repository for our ACA project evaluating branch predictors in SimpleScalar.

This work connects to modern CPU–LLM interaction: large language models (LLMs) depend heavily on efficient processor microarchitecture. Their high token-throughput demand stresses front-end performance, and branch prediction efficiency becomes critical when running transformer inference kernels on general-purpose CPUs. By studying classical predictors (bimodal, 2-level, comb, etc.) in a controlled SimpleScalar environment, we outline how prediction accuracy and CPI/IPC balance impact real-world workloads, including LLM runtimes that rely on dense linear algebra and control-heavy host code.

