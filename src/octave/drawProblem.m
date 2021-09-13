function drawProblem
  r = randn(10, 10000000) * 0.01;
  rsum = cumsum(r, 2);
  rmax = max(rsum);
##  plot(rmax)
  plot(rsum')
  title 'Rewards changing randomly with step sizes from Gaussian Distribution'
endfunction