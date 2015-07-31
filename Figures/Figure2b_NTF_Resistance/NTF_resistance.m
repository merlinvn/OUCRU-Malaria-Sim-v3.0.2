clear;
figure;
utl_column = 187;


% export as 12" by 7", fixed font size at 6, eps
A = dlmread('beta_0p14_k_4_hl_4p5_9_28_v3.0.1.txt');


strategy = {'MFT' 'Seq Depl' 'Cycling'};

sIndex = [2 3 1];

fraction = [0.5 0.6 0.7 0.8 0.9];
CR = [0.01 0.005 0.001];

strat_colors={[0.0 0.6 0.0], [0.84 0.52 0.24], [0.8 0.12 0.12]};
strat_colors_fill={[0.35 0.9 0.35], [1.0 0.82 0.49], [1.0 0.43 0.43]};

count = 0;

lw=2.5;
fs = 12;
nc=5;
nr=3;


% 162 --- 0.1%
% 163 --- 0.5%
% 164 --- 1%
% 165 --- 5%
% 166 --- 10%
% 167 --- 25%
re_index = 164; % Nguyen, is this the correct column for 1% resistance? yes
start_treatment_day = 4000;

A(A(:,re_index)==-1,re_index)=11300+365;
A(:,re_index) = (A(:,re_index)-4000)/365;
size_data = 4;
for cr = CR
    for f=fraction
        count = count+1;
        
        subaxis(nr,nc,count, 'Spacing', 0.03, 'Padding', 0, 'Margin', 0.07);
%         subplot(2,3,count);
        
        for i=size(strategy,2):-1:1            
            B = A(((A(:,13)==sIndex(i)) & (A(:,5)==f)& A(:,6)==cr),:);
            
            if(sIndex(i)==1)               
                h3 = scatter( B(:,14), B(:,re_index), 'MarkerFaceColor', strat_colors_fill{3}, 'MarkerEdgeColor', strat_colors{3}, 'SizeData', size_data ); hold on;
            else if(sIndex(i)==2)
                    h1 = scatter( B(:,14), B(:,re_index), 'MarkerFaceColor', strat_colors_fill{1}, 'MarkerEdgeColor', strat_colors{1}, 'SizeData', size_data ); hold on;
                else if (sIndex(i)==3)
                        h2 = scatter( B(:,14), B(:,re_index), 'MarkerFaceColor', strat_colors_fill{2}, 'MarkerEdgeColor', strat_colors{2}, 'SizeData', size_data ); hold on;
                    end
                end
            end
            
            %axis([0 16 0 22]);
            axis([0 8 0 13]);
            
%             q = quantile( B(:,13), [.25 .75] );
%             
%             line( [q(1) q(1)], [i-0.3 i+0.3], 'LineStyle', '--', 'Color', 'r', 'LineWidth', lw );
%             line( [q(2) q(2)], [i-0.3 i+0.3], 'LineStyle', '--', 'Color', 'r', 'LineWidth', lw );
%             
            if(count> nc*(nr-1))
                %xlabel({'NTF per year per 100 population','1M population size'});
            end
            
            
            if(mod(count,nc)==1)
                %ylabel({'Time until total resistance reach 1%',sprintf('CR=%0.3f',cr)});
                %axis([2.5 3.5 0.5 3.5]);
            else

                set(gca, 'YTickLabel', {});
                
            end
            
        end
        if (count<=nc)
            %title(sprintf('Fraction treated = %0.3f',f));
        end
        
        if(mod(count,nc)==1)
            %axis([0 6 0 (11000-start_treatment_day)/365]);
        else
            %axis([0 6.5 0 (11000-start_treatment_day)/365]);
        end
        
        %     axis tight;
        %     axis off;
    end
end

legend([h1 h2 h3], strategy, 'Location','NorthEast');
%suplabel('3 ACT with 95% Efficacy','t')