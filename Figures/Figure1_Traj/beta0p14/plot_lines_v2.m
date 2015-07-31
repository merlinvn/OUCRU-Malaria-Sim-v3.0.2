%export as 9"x7", scale 100% min font 8.
%
% EPS export : export 6 wide by 8 high, fixed font size 7.


clear;


%process data


%A  = dlmread('results_beta0p13_f0p5_cr0p005_3act.txt');
%A  = dlmread('results_beta0p13_f0p5_cr0p005_cycling.txt');
%A  = dlmread('results_beta0p13_f0p5_cr0p005_seq.txt');


A_3 = dlmread('results_beta0p14_k4_f0p6_cr0p005_3act.txt');
A_C  = dlmread('results_beta0p14_k4_f0p6_cr0p005_cycling.txt');
A_S  = dlmread('results_beta0p14_k4_f0p6_cr0p005_seq.txt');


B_3 = [];
B_C = [];
B_S = [];

NTF_3 = [];
NTF_C = [];
NTF_S = [];

n_runs = 100;
for i=1:1:n_runs
%2:378

    B_3= [B_3 A_3((i-1)*377+1:i*377,12)];
    NTF_3= [NTF_3 A_3((i-1)*377+1:i*377,5)];
    
    B_C= [B_C A_C((i-1)*377+1:i*377,12)];
    NTF_C= [NTF_C A_C((i-1)*377+1:i*377,5)];
    
    B_S= [B_S A_S((i-1)*377+1:i*377,12)];
    NTF_S= [NTF_S A_S((i-1)*377+1:i*377,5)];
    
end

t = NTF_3;
t = [zeros(1,100);t];
t(end,:) = [];
NTF_3 = NTF_3 -t;

t = NTF_C;
t = [zeros(1,100);t];
t(end,:) = [];
NTF_C = NTF_C -t;

t = NTF_S;
t = [zeros(1,100);t];
t(end,:) = [];
NTF_S = NTF_S -t;



C = transp(B_3);

nc=1;
nr=3;

fs = 10;
x = -4000:30:11280-4000;

fillcolor2 = [0.89 0.83 1.0];
edge_color2 = [0.89 0.83 1.0];
%fillcolor2 = [0.98 0.95 1.0];
%edge_color2 = [0.98 0.95 1.0];

fillcolor = [0.82 0.76 1.0];
edge_color = [0.82 0.76 1.0];
%fillcolor = [0.8945 0.8169 1.0];
%edge_color = [0.8945 0.8169 1.0];
%fillcolor = 1.0 - (1.0 - (0.2)*[0 191/255 1]);
%edge_color = [0.71 0.6 1];

myLightGray = [0.6 0.6 0.6];

l_time = 0.0;
r_time = 7300;
text_x  = 15*365;
text_x2 = 365;
text_y = 8.75;

prevalence_from =0;
prevalence_to =9.9;
yticks = 2:2:prevalence_to;
yticklabels = {'2%','4%','6%','8%'};

scale_factor = 5000;

%ntf #5 med_ntf from Figure 1 plot
med_ntf = [3.56000000000000,5.11000000000000,4.59000000000000];
up_ntf = [4.29000000000000,5.65500000000000,5.50000000000000];
down_ntf = [2.98500000000000,4.70500000000000,4.15500000000000];

%=======================================
subaxis(nr,nc,3, 'Spacing', 0.03, 'Padding', 0, 'Margin', 0.07);
blood_slide_quantile_3 = quantile(B_3,[.05 .25 .50 .75 .95],2);
ntf_quantile_3 = quantile(NTF_3,[.05 .25 .50 .75 .95],2);

plot([0 7300], [5 5], '--','LineWidth', 1, 'Color', myLightGray); hold on;
%plot(-4000:30:11280-4000, blood_slide_quantile_3);
fill([x,fliplr(x)],[transpose(blood_slide_quantile_3(:,1)),fliplr(transpose(blood_slide_quantile_3(:,5)))],fillcolor2,'edgecolor',edge_color2);hold on;
fill([x,fliplr(x)],[transpose(blood_slide_quantile_3(:,2)),fliplr(transpose(blood_slide_quantile_3(:,4)))],fillcolor,'edgecolor',edge_color);hold on;
plot(x,blood_slide_quantile_3(:,3), 'k', 'LineWidth', 1);
%plot(x, blood_slide_quantile_3(:,2), 'k--');
%plot(x, blood_slide_quantile_3(:,4), 'k--');

%plot(x, ntf_quantile_3(:,3)/scale_factor, 'b','LineWidth', 2);


box off;
axis([l_time r_time prevalence_from prevalence_to]);
set(gca, 'XTick', 0:365*3:7300);
%set(gca, 'XTickLabel', {}, 'FontSize', fs);
set(gca, 'XTickLabel', 0:3:20, 'FontSize', fs);
set(gca, 'YTick', yticks, 'FontSize', fs);
set(gca, 'YTickLabel', yticklabels, 'FontSize', fs);
%set(gca, 'YTickLabel', 0:1:prevalence_to, 'FontSize', fs);
%%set(gca, 'XTickLabel', 0:5:20, 'FontSize', fs);
ylabel('blood-slide prevalence');
text(text_x, text_y, sprintf('NTF: %0.2f (%0.2f - %0.2f)',med_ntf(1),down_ntf(1), up_ntf(1)));
text(text_x2, text_y, 'Multiple First-Line Therapies' );
xlabel('Years');
%title('MFT');




%==================
subaxis(nr,nc,2, 'Spacing', 0.03, 'Padding', 0, 'Margin', 0.07);
blood_slide_quantile_S = quantile(B_S,[.05 .25 .50 .75 .95],2);
ntf_quantile_S = quantile(NTF_S,[.05 .25 .50 .75 .95],2);


plot([0 7300], [5 5], '--','LineWidth', 1, 'Color', myLightGray); hold on;
fill([x,fliplr(x)],[transpose(blood_slide_quantile_S(:,1)),fliplr(transpose(blood_slide_quantile_S(:,5)))],fillcolor2,'edgecolor',edge_color2);hold on;
fill([x,fliplr(x)],[transpose(blood_slide_quantile_S(:,2)),fliplr(transpose(blood_slide_quantile_S(:,4)))],fillcolor,'edgecolor',edge_color);hold on;
%plot(x, blood_slide_quantile_S(:,2), 'k--');
plot(x,blood_slide_quantile_S(:,3), 'k', 'LineWidth', 1);
%plot(x, blood_slide_quantile_S(:,4), 'k--');

%plot(x, ntf_quantile_S(:,3)/scale_factor, 'b','LineWidth', 2);


box off;
axis([l_time r_time prevalence_from prevalence_to]);
set(gca, 'XTick', 0:365*3:7300);
set(gca, 'XTickLabel', {}, 'FontSize', fs);
set(gca, 'XTickLabel', {}, 'FontSize', fs);
set(gca, 'YTick', yticks, 'FontSize', fs);
set(gca, 'YTickLabel', yticklabels, 'FontSize', fs);
ylabel('blood-slide prevalence');

text(text_x, text_y, sprintf('NTF: %0.2f (%0.2f - %0.2f)',med_ntf(2),down_ntf(2), up_ntf(2)));
text(text_x2, text_y, 'Sequential Deployment' );

%set(gca, 'XTickLabel', 0:5:20, 'FontSize', fs);
%set(gca, 'YTickLabel', {}, 'FontSize', fs);
%ylabel('Blood-slide Prevalence');
%xlabel('Years');
%title('Sequencial Deployment');

%==================
subaxis(nr,nc,1, 'Spacing', 0.03, 'Padding', 0, 'Margin', 0.07);
blood_slide_quantile_C = quantile(B_C,[.05 .25 .50 .75 .95],2);
ntf_quantile_C = quantile(NTF_C,[.05 .25 .50 .75 .95],2);

plot([0 7300], [5 5], '--','LineWidth', 1, 'Color', myLightGray); hold on;
%plot(-4000:30:11280-4000,blood_slide_quantile_C);
fill([x,fliplr(x)],[transpose(blood_slide_quantile_C(:,1)),fliplr(transpose(blood_slide_quantile_C(:,5)))],fillcolor2,'edgecolor',edge_color2);hold on;
fill([x,fliplr(x)],[transpose(blood_slide_quantile_C(:,2)),fliplr(transpose(blood_slide_quantile_C(:,4)))],fillcolor,'edgecolor',edge_color);hold on;
plot(x,blood_slide_quantile_C(:,3), 'k', 'LineWidth', 1);   
%plot(x, blood_slide_quantile_C(:,2), 'k--');
%plot(x, blood_slide_quantile_C(:,4), 'k--');



box off;
axis([l_time r_time prevalence_from prevalence_to]);
set(gca, 'XTick', 0:365*3:7300);

%set(gca, 'XTickLabel', 0:3:20, 'FontSize', fs);
set(gca, 'YTick', yticks, 'FontSize', fs);
set(gca, 'YTickLabel', yticklabels, 'FontSize', fs);
set(gca, 'XTickLabel', {}, 'FontSize', fs);
%set(gca, 'YTickLabel', {}, 'FontSize', fs);
%ylabel('Blood-slide Prevalence');
%xlabel('Time (year)');
%title('5-year Cycling');
ylabel('blood-slide prevalence');

text(text_x, text_y, sprintf('NTF: %0.2f (%0.2f - %0.2f)',med_ntf(3),down_ntf(3), up_ntf(3)));
text(text_x2, text_y, '5-year Cycling' );
