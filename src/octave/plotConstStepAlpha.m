function plotConstStepAlpha
  fig = figure;
  subplot(1,2,1)
  hold on
  title 'Optimal choice ratio'
  ylim([0 1])
  subplot(1,2,2)
  hold on
  title 'Average rewards'
  for alpha = [1 .5 .1 .01 .001]
    expdata = dlmread(sprintf('const_step_alpha_%.2f_results_eps_0.10.txt', alpha));
    subplot(1,2,1)
    plot(expdata(1, :))
    subplot(1,2,2)
    plot(expdata(2, :), 'displayname', sprintf('\\alpha = %.3f', alpha))
  endfor
  legend show
  legend('fontsize', 15, 'location', 'eastoutside')
endfunction