function plotComparison
  fig = figure;
  subplot(1,2,1)
  hold on
  title 'Optimal choice ratio'
  ylim([0 1])
  subplot(1,2,2)
  hold on
  title 'Average rewards'
  eps = dlmread('comparison_epsilon.txt');
  grd = dlmread('comparison_greedy.txt');
  subplot(1,2,1)
  hold on
  plot(eps(1, :))
  plot(grd(1, :), 'or')
  plot(grd(1, :), 'b')
  subplot(1,2,2)
  hold on
  plot(eps(2, :), ';\epsilon-greedy;')
  plot(grd(2, :), ';Optimistic greedy;')
  legend show
  legend('fontsize', 15, 'location', 'eastoutside')
endfunction
