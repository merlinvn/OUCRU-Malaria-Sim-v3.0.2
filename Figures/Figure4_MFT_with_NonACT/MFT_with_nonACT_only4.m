% export at 10" by 6", fixed font size of 8, to eps

clear all;
%95% Efficacy
A = dlmread('3act_k4.txt');
A95 = dlmread('2act_95_k4.txt');
A85 = dlmread('2act_85_k4.txt');
A75 = dlmread('2act_75_k4.txt');


BK4 = cat(3, A, A95, A85, A75);

A_k0p5 = dlmread('3act_k0p5.txt');
A95_k0p5 = dlmread('2act_95_k0p5.txt');
A85_k0p5 = dlmread('2act_85_k0p5.txt');
A75_k0p5 = dlmread('2act_75_k0p5.txt');

BK1 = cat(3, A_k0p5, A95_k0p5, A85_k0p5, A75_k0p5);

ND=size(BK1,3);


%y_label = {'3 ACTs','2 ACTs + non-ACT 95% Eff' ,'2 ACTs + non-ACT 85% Eff' , '2 ACTs + non-ACT 75% Eff', ''};
y_label = {'3 ACTs','95%' ,'85%' , '75%', ''};


ntf_column = 14;
lw=2.5;
n_row = size(BK1,1);
qmarks=[.25 .75];
jt=0.3;



%myFillColor = [0.15 0.85 1.0];
myFillColor = [0.35 0.9 0.35];
myLineColor = [0.0 0.6 0.0];
myLightGray = [0.85 0.85 0.85];

ntf_l = 0;
ntf_r = 7;

numsd=2.0;

% scaling factor for the height of the normal distribution
% sf = 0.6;


% bottom range of axes
bt = 0.6;

norm_amp = 0.7;

subaxis(2,2,1, 'Spacing', 0.03, 'Padding', 0.01, 'Margin', 0.09);
for i = 1:ND
    C = BK1(:,:,i);

    % This uses the Lilliefors test to determine if the data come from a
    % normal distribution or not
    %[h,p] = lillietest( C(:,ntf_column) );
    %p;

    % compute the mean and sd for this set of NTF values
    mu = mean(C(:,ntf_column));
    sd = std(C(:,ntf_column));
    x = (mu-numsd*sd):0.01:(mu+numsd*sd);
    nn= size(x,2);
    b = ones(1,nn);
    y = norm_amp*normpdf( x, mu, sd );
    
    % define the end points of the x-vector above
    xl = x(1);
    xr = x(size(x,2));
    
    plot( [ntf_l ntf_r], [i i], 'Color', myLightGray ) ; hold on;
    box off;
    
    % make these points white so they are invisible
    scatter( C(:,ntf_column), i*ones(n_row,1), 'wo', 'MarkerFaceColor', 'w', 'SizeData', 1 ); hold on;
    %title('Mutation probability proportional to drug concentration');
    
    % this loop plots the outliers that are more than 2*sd away
    for r=1:n_row
        ntf_val = C(r,ntf_column);
        if ntf_val > mu+numsd*sd
            scatter( ntf_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
        if ntf_val < mu-numsd*sd
            scatter( ntf_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
    end
    axis([ntf_l ntf_r bt 5]);
    
    % this plots the normal distribution line showing the distribution of
    % the majority of NTF values
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    x_fill=[x,fliplr(x)]; 
    y_fill=[i*b,fliplr(y+i)];  
    fill( x_fill, y_fill, myFillColor );
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    line([xr, xr], [i, i+ y(size(y,2))], 'Color', myLineColor, 'LineWidth', 1 );
    line([xl, xl], [i, i+ y(1)], 'Color', myLineColor, 'LineWidth', 1 );
end

set(gca, 'YTick', 1:1:7 );
set(gca, 'YTickLabel', y_label);
%text( 3.7, 3.1, 'a','FontName', 'Calibri','FontSize', 8, 'FontAngle','italic' );    

subaxis(2,2,3, 'Spacing', 0.03, 'Padding', 0.01, 'Margin', 0.09);
for i = 1:ND
    C = BK4(:,:,i);

    % This uses the Lilliefors test to determine if the data come from a
    % normal distribution or not
    %[h,p] = lillietest( C(:,ntf_column) );
    %p;

    % compute the mean and sd for this set of NTF values
    mu = mean(C(:,ntf_column));
    sd = std(C(:,ntf_column));
    x = (mu-numsd*sd):0.01:(mu+numsd*sd);
    nn= size(x,2);
    b = ones(1,nn);
    y = norm_amp*normpdf( x, mu, sd );

    % define the end points of the x-vector above
    xl = x(1);
    xr = x(size(x,2));

    plot( [ntf_l ntf_r], [i i], 'Color', myLightGray ) ; hold on;
    box off;

    % make these points white so they are invisible
    scatter( C(:,ntf_column), i*ones(n_row,1), 'wo', 'MarkerFaceColor', 'w', 'SizeData', 1 ); hold on;
    %title('Mutation probability highest at intermediate drug concentrations');
    
    % this loop plots the outliers that are more than 2*sd away
    for r=1:n_row
        ntf_val = C(r,ntf_column);
        if ntf_val > mu+numsd*sd
            scatter( ntf_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
        if ntf_val < mu-numsd*sd
            scatter( ntf_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
    end
    axis([ntf_l ntf_r bt 5]);
    
    % this plots the normal distribution line showing the distribution of
    % the majority of NTF values
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    x_fill=[x,fliplr(x)]; 
    y_fill=[i*b,fliplr(y+i)];  
    fill( x_fill, y_fill, myFillColor );
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    line([xr, xr], [i, i+ y(size(y,2))], 'Color', myLineColor, 'LineWidth', 1 );
    line([xl, xl], [i, i+ y(1)], 'Color', myLineColor, 'LineWidth', 1 );
end


set(gca, 'YTick', 1:1:5 );
set(gca, 'YTickLabel', y_label);
xlabel('NTF');





%%%%%%%%%%%%%%%%%%%%%%%
%
%
%
%  the two right hand plot will show
%  will show time to 1% artemisinin resistance
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%


numsd=1.0;

time_total_1p_column = 170;
tt1p_l = 0.0;
tt1p_r = 20.0;

gamma_amp=3.6;
median_t = [];
subaxis(2,2,2, 'Spacing', 0.03, 'Padding', 0.01, 'Margin', 0.09);

for i = 1:ND
    C  = BK1(:,:,i);
    
    C(C(:,time_total_1p_column)==-1,time_total_1p_column)=11300+365;
    
    CC = (C(:,time_total_1p_column)-4000)/365;

    % This uses the Lilliefors test to determine if the data come from a
    % normal distribution or not
    [h,p] = lillietest( CC );
    p
    median_t = [median_t; median(CC)];
    % compute the mean and sd for this set of NTF values
    mu = mean( CC );
    sd = std( CC );
    %x = (mu-numsd*sd):0.01:(mu+numsd*sd);
    %x = 2.0:0.01:10.0;

    %y = norm_amp*normpdf( x, mu, sd );
    gam_b = sd*sd/mu;
    gam_a = mu / gam_b;
    [params_hat, params_ci] = gamfit(CC);
    xl = icdf('Gamma', 0.05, params_hat(1), params_hat(2) );
    xr = icdf('Gamma', 0.95, params_hat(1), params_hat(2) );
    x = xl:0.01:xr;
    nn= size(x,2);
    b = ones(1,nn);
    y = gamma_amp*gampdf( x, params_hat(1), params_hat(2) );
    
    plot( [tt1p_l tt1p_r], [i i], 'Color', myLightGray ) ; hold on;
    box off;

    % make these points white so they are invisible
    scatter( C(:,time_total_1p_column), i*ones(n_row,1), 'wo', 'MarkerFaceColor', 'w', 'SizeData', 1 ); hold on;
    %title('Mutation probability proportional to drug concentration');
    
    % this loop plots the outliers that are more than 2*sd away
    for r=1:n_row
        tt1p_val = CC(r);
        if tt1p_val > xr
            scatter( tt1p_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
        if tt1p_val < xl
            scatter( tt1p_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
    end
    axis([tt1p_l tt1p_r bt 5]);
    
    % this plots the normal distribution line showing the distribution of
    % the majority of NTF values
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    x_fill=[x,fliplr(x)]; 
    y_fill=[i*b,fliplr(y+i)];  
    fill( x_fill, y_fill, myFillColor );
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );    
    line([xr, xr], [i, i+ y(size(y,2))], 'Color', myLineColor, 'LineWidth', 1 );
    line([xl, xl], [i, i+ y(1)], 'Color', myLineColor, 'LineWidth', 1 );
end

set(gca, 'YTick', 1:1:7 );
set(gca, 'YTickLabel', {''});





subaxis(2,2,4, 'Spacing', 0.03, 'Padding', 0.01, 'Margin', 0.09);
median_t4 = [];
for i = 1:ND
    C  = BK4(:,:,i);
    
    C(C(:,time_total_1p_column)==-1,time_total_1p_column)=11300+365;
    
    CC = (C(:,time_total_1p_column)-4000)/365;

    % This uses the Lilliefors test to determine if the data come from a
    % normal distribution or not
    [h,p] = lillietest( CC );
    p

    % compute the mean and sd for this set of NTF values
    mu = mean( CC );
    median_t4 = [median_t4; median(CC)];
    sd = std( CC );
    %x = (mu-numsd*sd):0.01:(mu+numsd*sd);
    %x = 2.0:0.01:10.0;

    %y = norm_amp*normpdf( x, mu, sd );
    gam_b = sd*sd/mu;
    gam_a = mu / gam_b;
    [params_hat, params_ci] = gamfit(CC);
    xl = icdf('Gamma', 0.05, params_hat(1), params_hat(2) );
    xr = icdf('Gamma', 0.95, params_hat(1), params_hat(2) );
    x = xl:0.01:xr;
    nn= size(x,2);
    b = ones(1,nn);
    y = gamma_amp*gampdf( x, params_hat(1), params_hat(2) );

    plot( [tt1p_l tt1p_r], [i i], 'Color', myLightGray ) ; hold on;
    box off;
    
    % make these points white so they are invisible
    scatter( C(:,time_total_1p_column), i*ones(n_row,1), 'wo', 'MarkerFaceColor', 'w', 'SizeData', 1 ); hold on;    
    %title('Mutation probability highest at intermediate drug concentrations');
    
    % this loop plots the outliers that are more than 2*sd away
    for r=1:n_row
        tt1p_val = CC(r);
        if tt1p_val > xr
            scatter( tt1p_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
        if tt1p_val < xl
            scatter( tt1p_val, i+0.04, 'ko', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
        end
    end
    axis([tt1p_l tt1p_r bt 5]);
    
    % this plots the normal distribution line showing the distribution of
    % the majority of NTF values
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    x_fill=[x,fliplr(x)]; 
    y_fill=[i*b,fliplr(y+i)];  
    fill( x_fill, y_fill, myFillColor );
    line( x, y+i, 'Color', myLineColor, 'LineWidth', 1 ); 
    line( x, i, 'Color', myLineColor, 'LineWidth', 1 );
    line([xr, xr], [i, i+ y(size(y,2))], 'Color', myLineColor, 'LineWidth', 1 );
    line([xl, xl], [i, i+ y(1)], 'Color', myLineColor, 'LineWidth', 1 );
end

set(gca, 'YTick', 1:1:7 );
set(gca, 'YTickLabel', {''});

xlabel('Years Until 1% Artemisinin Resistance');

