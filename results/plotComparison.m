function plotComparison
  fig = figure;
  subplot(2,2,[1])
  hold on
  title 'Optimal choice ratio'
  ylim([0 1])
  subplot(2,2,[2 4])
  hold on
  title 'Average rewards'
  eps = dlmread('comparison_epsilon.txt');
  grd = dlmread('comparison_greedy.txt');
  subplot(2,2,[1])
  hold on
  plot(eps(1, :))
  plot(grd(1, :), 'or')
  plot(grd(1, :), 'b')
  subplot(2,2,[2 4])
  hold on
  plot(eps(2, :), ';\epsilon-greedy;')
  plot(grd(2, :), ';Optimistic greedy;')
  legend show
  legend('fontsize', 15, 'location', 'eastoutside')
  subplot(2,2,[3])
  plot(grd(3, :))
  
  t = 1:5000;
  y = 5 - exp(-t)
endfunction
