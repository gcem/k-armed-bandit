function plotChanging
  fig = figure;
  subplot(1,2,1)
  hold on
  title 'Optimal choice ratio'
  ylim([0 1])
  subplot(1,2,2)
  hold on
  title 'Average rewards'
  for epsilon = [0 0.01 0.1]
    expdata = dlmread(sprintf('changing_results_eps_%.2f.txt', epsilon));
    subplot(1,2,1)
    plot(expdata(1, :))
    subplot(1,2,2)
    plot(expdata(2, :), 'displayname', sprintf('\\epsilon = %.3f', epsilon))
  endfor
  legend show
  legend('fontsize', 15, 'location', 'eastoutside')
endfunction