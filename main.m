clear all
close all
clc

% the code is protected for now, but you can run the scenarios to see the
% result. You just need to choose the value of scenario in the next line.
scenario=4;

if scenario==0
    run scenario_1_pso.p
elseif scenario==1
    run scenario_1_de.p
elseif scenario==2
    run scenario_2_de.p
elseif scenario==3
    run scenario_3_de.p
else
    run scenario_4_de.p
end