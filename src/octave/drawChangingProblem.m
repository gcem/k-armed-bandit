function drawChangingProblem
  steps = randn(1000, 300000) * 0.01;
  steps(:, 1) = 0;
  tot = cumsum(steps);
  plot(max(tot', 1))
endfunction