clear;
%export as 12" by 2", eps, scale fonts by 100%, min size of 5


% Pop Size is 1M here
%A = dlmread('results.beta0p13.cv2p0.HL1d.Mar03.txt');
A = dlmread('beta_0p14_k_4_hl_4p5_9_28_v3.0.1.txt');

strategy = {'MFT' 'Seq Depl' 'Cycling'};

sIndex = [2 3 1];

fraction = [0.5 0.6 0.7 0.8 0.9];
CR = [0.01 0.005 0.001];
cr_colors={[0.0 0.6 0.0], [0.84 0.52 0.24], [0.8 0.12 0.12]};
cr_colors_fill={[0.35 0.9 0.35], [1.0 0.82 0.49], [1.0 0.43 0.43]};
count = 0;

lw=2.5;
fs = 12;
nc=5;
nr=1;
re_index = 164;
start_treatment_day = 4000;

jt=0.1;

ntf_l =-1;
ntf_r = 18;
myFillColor = [0.15 0.85 1.0];
myLightGray = [0.85 0.85 0.85];

ntf_column = 14;
numsd = 1.5;
norm_amp=0.8;
dotsize = 4.0;
fs=6;

A(A(:,re_index)==-1,re_index)=11300+365;
A(:,re_index) = (A(:,re_index)-4000)/365;

% this is the threshold value for NTF; if it's below this value we simply
% plot it; and if it's above this value we assign it to the group of NTF
% values that will be used for a normal distribution fit
th_ntf = 0.25;

% half of the box width
bw=0.3;

med_ntf = zeros(15,3);
up_quantile_ntf = zeros(15,3);
down_quantile_ntf = zeros(15,3);
med_utl = zeros(15,3);


%A(A(:,187)==-1,187)=11300+365;
%A(:,187) = A(:,187)/365;
set(gcf,'Renderer','OpenGL');
for f=fraction
    
    count = count+1;
    subaxis(nr,nc,count, 'Spacing', 0.03, 'Padding', 0, 'Margin', 0.07);
    
    for cr = CR
        
        for i=1:1:size(strategy,2)
            
            B = A(((A(:,13)==sIndex(i)) & (A(:,5)==f)& A(:,6)==cr),:);
            mm = size(B,1);
            
            vos=1;
            if cr == 0.005
                vos=2;
            end
            if cr == 0.01
                vos=3;
            end
            
            vert_pos = (3.5)*(vos-1) + i;
            
            % put a standard horizontal gray line on the graph
            plot( [ntf_l ntf_r], [vert_pos vert_pos], 'Color', myLightGray ) ; hold on;
            
            box off;
            
            %scatter( B(:,14), i*(ones(mm,1)+jt*(rand(mm,1)-0.5)), 'k', 'MarkerFaceColor', 'k', 'SizeData', 8 ); hold on;
            
            ind1 = B(:,ntf_column) < th_ntf;
            zr = sum(ind1);
            %text( 0.6 , i+0.3 , sprintf('%1.1f%%', 100*zr/mm), 'FontSize', 8);
            ind2 = B(:,ntf_column) >= th_ntf;
            
            q = quantile( B(ind2,ntf_column), [.25 .50 .75] );
            med_ntf( 3*(count-1) + vos, i ) = q(2);
            up_quantile_ntf( 3*(count-1) + vos, i ) = q(3);
            down_quantile_ntf( 3*(count-1) + vos, i ) = q(1);
            
            
            q2 = quantile( B(:,187), [.25 .50 .75] );
            med_utl( 3*(count-1) + vos, i ) = q2(2);
            
            
            
            step=(q(3)-q(1))/1000;
            x=q(1):step:q(3);
            szx=size(x,2);
            yb = (vert_pos-bw)*ones(1,szx);
            yt = (vert_pos+bw)*ones(1,szx);
            lw=1;
            line( x, yb, 'Color', cr_colors{i}, 'LineWidth', lw );
            line( x, yt, 'Color', cr_colors{i}, 'LineWidth', lw );
            x_fill=[x,fliplr(x)];
            y_fill=[yb,fliplr(yt)];
            fill( x_fill, y_fill, cr_colors_fill{i} );
            
            adj = 0.03;
            
            lw=1;
            line( [q(1) q(1)], [vert_pos-bw, vert_pos+bw], 'Color', cr_colors{i}, 'LineWidth', lw );
            line( [q(2) q(2)], [vert_pos-bw, vert_pos+bw], 'Color', cr_colors{i}, 'LineWidth', lw );
            line( [q(3) q(3)], [vert_pos-bw, vert_pos+bw], 'Color', cr_colors{i}, 'LineWidth', lw );
            line( [q(1)-adj q(3)+adj], [vert_pos+bw, vert_pos+bw], 'LineStyle', '-', 'Color', cr_colors{i}, 'LineWidth', lw );
            line( [q(1)-adj q(3)+adj], [vert_pos-bw, vert_pos-bw], 'Color', cr_colors{i}, 'LineWidth', lw );
            
            if( f > 0.6)
                text( -0.25, vert_pos, sprintf('%2.0f', 100*zr/mm), 'FontSize', 5 );
            end
            % now plot the outliers that are more than 2*sd away
            BB = B(ind2,ntf_column);
            BBB = BB(BB>q(3)|BB<q(1));
            scatter( BBB, ones(size(BBB))*vert_pos, 'ko', 'MarkerFaceColor', 'k', 'SizeData', dotsize );
        end
        
        if (count<=nc)
            %title(sprintf('f = %0.1f',f));
        end
        
        
        %     axis tight;
        %     axis off;
    end
    
    set(gca, 'YTick', [1 2 3 4.5 5.5 6.5 8 9 10] );
    if(count==1)
        set(gca, 'YTickLabel', strategy, 'FontSize', fs);
    else
        set(gca, 'YTickLabel', {});
    end
    
    set(gca, 'XTick', 0:1:8);
    set(gca, 'XTickLabel', 0:1:8, 'FontSize', fs);
    xlabel({'NTF'});
    axis([-0.5 8 0.5 11.0]);
    
end



