close all
clear all

% % Leitura dos dados

[ sm_cod,sm_ano,sm_DJ,sm_dia, sm_mes, sm_HH,sm_MM,xx,sm_Bateria,sm_Ptemp,sm_u,sm_v,sm_w,sm_Ts,sm_Td,sm_e,sm_es,sm_VPD,sm_RHs,sm_H2O_mix_ratio,sm_H2O_flux,incertzH2O, storageH2O , FlagH2o  ,sm_ET,sm_LE,incLE,stgLE,FLE,sm_H,incH,stgH,FH,sm_BRatio,sm_CO2_mix_ratio,sm_CO2,incCO2,stgCO2,FCO2,sm_CH4_mix_ratio,sm_CH4,incCH4,stgCH4,FCH4,sm_L,sm_ustar,sm_Tstar,sm_TKE,sm_Tau,incTau,stgTau,FTau,sm_vento,sm_dirvento,sm_Temp,sm_RH,sm_Rg,sm_Pmb,sm_Prec,sm_Fsolo1,sm_Tsolo1,sm_Rn,sm_PAR,sm_SWout,sm_LWin,sm_Lout,sm_Fsolo2,sm_Fsolo3,sm_Tsolo2,sm_Tsolo3,sm_H2OSolo1,sm_H2OSolo2,sm_H2OSolo3,sm_H2OSolo4,xx,xx,xx,xx,xx,xx,xx,xx,xx,sm_u_var,sm_v_var,sm_w_var,xx, xx,xx,xx,xx,sm_T_in,sm_RH_in,sm_PO_in, sm_P_in, sm_ws_in, sm_wd_in, sm_Rg_in,sm_Prec_in,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx] =... 
 textread('dados_SM_from_324_2013_to_348_2014.txt','%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ','headerlines',0,'delimiter',',');

sm_Bateria(find(sm_Bateria==-999.99))=NaN; 
sm_Ptemp(find(sm_Ptemp==-999.99))=NaN;
sm_u(find(sm_u==-999.99))=NaN;
sm_v(find(sm_v==-999.99))=NaN;
sm_w(find(sm_w==-999.99))=NaN;
sm_Ts(find(sm_Ts==-999.99))=NaN;
sm_Td(find(sm_Td==-999.99))=NaN;
sm_e(find(sm_e==-999.99))=NaN;
sm_es(find(sm_es==-999.99))=NaN;
sm_VPD(find(sm_VPD==-999.99))=NaN;
sm_RHs(find(sm_RHs==-999.99))=NaN;
sm_H2O_mix_ratio(find(sm_H2O_mix_ratio==-999.99))=NaN;
sm_H2O_flux(find(sm_H2O_flux==-999.99))=NaN;
sm_ET(find(sm_ET==-999.99))=NaN;
sm_H(find(sm_H==-999.99))=NaN;
sm_LE(find(sm_LE==-999.99))=NaN;
sm_BRatio(find(sm_BRatio==-999.99))=NaN;
sm_CO2_mix_ratio(find(sm_CO2_mix_ratio==-999.99))=NaN;
sm_CO2(find(sm_CO2==-999.99))=NaN;
sm_CH4_mix_ratio(find(sm_CH4_mix_ratio==-999.99))=NaN;
sm_CH4(find(sm_CH4==-999.99))=NaN;
sm_L(find(sm_L==-999.99))=NaN;
sm_ustar(find(sm_ustar==-999.99))=NaN;
sm_Tstar(find(sm_Tstar==-999.99))=NaN;
sm_TKE(find(sm_TKE==-999.99))=NaN;
sm_Tau(find(sm_Tau==-999.99))=NaN;
sm_vento(find(sm_vento==-999.99))=NaN;
sm_dirvento(find(sm_dirvento==-999.99))=NaN;
sm_Temp(find(sm_Temp==-999.99))=NaN;
sm_RH(find(sm_RH==-999.99))=NaN;
sm_Rg(find(sm_Rg==-999.99))=NaN;
sm_Pmb(find(sm_Pmb==-999.99))=NaN;
sm_Prec(find(sm_Prec==-999.99))=NaN;
sm_Rn(find(sm_Rn==-999.99))=NaN;
sm_PAR(find(sm_PAR==-999.99))=NaN;
sm_SWout(find(sm_SWout==-999.99))=NaN;
sm_Lout(find(sm_Lout==-999.99))=NaN;
sm_LWin(find(sm_LWin==-999.99))=NaN;
sm_Fsolo1(find(sm_Fsolo1==-999.99))=NaN;
sm_Fsolo2(find(sm_Fsolo2==-999.99))=NaN;
sm_Fsolo3(find(sm_Fsolo3==-999.99))=NaN;
sm_Tsolo1(find(sm_Tsolo1==-999.99))=NaN;
sm_Tsolo2(find(sm_Tsolo2==-999.99))=NaN;
sm_Tsolo3(find(sm_Tsolo3==-999.99))=NaN;
sm_H2OSolo1(find(sm_H2OSolo1==-999.99))=NaN;
sm_H2OSolo2(find(sm_H2OSolo2==-999.99))=NaN;
sm_H2OSolo3(find(sm_H2OSolo3==-999.99))=NaN;
sm_H2OSolo4(find(sm_H2OSolo4==-999.99))=NaN;
sm_u_var(find(sm_u_var==-999.99))=NaN;
sm_v_var(find(sm_v_var==-999.99))=NaN;
sm_w_var(find(sm_w_var==-999.99))=NaN;
sm_H2OSolo1(find(sm_H2OSolo1>10))=NaN;
sm_H2OSolo2(find(sm_H2OSolo2>10))=NaN;
sm_H2OSolo3(find(sm_H2OSolo3>10))=NaN;
sm_H2OSolo4(find(sm_H2OSolo4>10))=NaN;
sm_Tsolo1(find(sm_Tsolo1>100))=NaN;
sm_Tsolo2(find(sm_Tsolo2>100))=NaN;
sm_Tsolo3(find(sm_Tsolo3>100))=NaN;

sm_Rg_in(find(sm_Rg_in==-999.99))=NaN;


sm_Fsolo=(sm_Fsolo1+sm_Fsolo2+sm_Fsolo3)/3.;
 sz=size(sm_cod);
nd=(sz(1,1)/48)-1



nnd=30; % a cada qtos dias coloca a data
lnd=nd/nnd+1;  % nd tem q ser multiplo de nnd
pnd=nnd*48;
for i=1:lnd
sm_dia(i)=sm_DJ(1+pnd*(i-1));
end

figure
plot(sm_Rg)
hold on
plot(sm_Rn,'r')
legend('Rg', 'Rn')
ylabel('Energy Density Flux (W m^{-2})')


figure
plot(sm_Rg)
hold on
plot(-sm_SWout,'r')
plot(sm_LWin,'k')
plot(-sm_Lout,'g')
plot (sm_Rn,':m')
legend('SWin','SWout','Lin','Lout','Rn')
ylabel('Energy Density Flux (W m^{-2})')

figure
plot(sm_LE)
hold on
plot(sm_H,'r')
plot(sm_Fsolo1,'k')
legend('Le', 'H', 'Fg')
ylabel('Energy Density Flux (W m^{-2})')




figure
plot(sm_LE+sm_H+sm_Fsolo1)
hold on
plot(sm_Rn,'r')
legend('H+Le+Fg', 'Rn')
ylabel('Energy Density Flux (W m^{-2})')


% sm_LE(find(sm_LE>1000))=NaN;
% sm_LE(find(sm_LE<-100))=NaN;
% sm_H(find(sm_H>1000))=NaN;
% sm_H(find(sm_H<-100))=NaN;
% sm_Fsolo(find(sm_Fsolo>1000))=NaN;
% sm_Fsolo(find(sm_Fsolo<-100))=NaN;

for i=1:nd*48
 if sm_Rg(i)<10
     if sm_LE(i)>200
         sm_LE(i)=NaN;
     end
      if sm_H(i)>200
         sm_H(i)=NaN;
     end
 end
end

figure
plot(sm_Fsolo,'k')
hold on
plot(sm_Fsolo2,'g')
plot(sm_Rg,'r')
legend( 'Fg','Fg2','Rg')
ylabel('Energy Density Flux (W m^{-2})')

figure
plot(sm_Fsolo,'k')
legend( 'Fg')
ylabel('Energy Density Flux (W m^{-2})')


figure
plot(sm_H,'r')
legend( 'H')
ylabel('Energy Density Flux (W m^{-2})')

figure
plot(sm_LE)
legend('Le')
ylabel('Energy Density Flux (W m^{-2})')
 
figure
plot(sm_Rn-sm_Fsolo)
hold on
plot(sm_LE+sm_H,'r')
legend('Rn-Fg', 'LE+H')
 ylabel('Energy Density Flux (W m^{-2})')
 

figure
plot((sm_Rn-sm_Fsolo),(sm_LE+sm_H),'.')
ylabel('Rn-Fg')
xlabel('Le+H')

albedo=nansum(sm_SWout(1:48*nd))/nansum(sm_Rg(1:48*nd))

figure
Rn_s=sm_LE+sm_H+sm_Fsolo+stgH+stgLE;
plot(sm_Rn-sm_Fsolo)
hold on
plot(sm_LE+sm_H,'r')
legend('Rn-Fg', 'LE+H')
 ylabel('Energy Density Flux (W m^{-2})')

 figure
 plot(sm_Rn-Rn_s)
 title('Residual: Rn-Le+H+Fg')
 
Residual=nanmean(sm_Rn-Rn_s);

figure
plot(sm_ET)
legend('ET')
ylabel('Evapotranspiration')
 
figure
plot(sm_BRatio)
legend ('Bowen Ratio')

figure
plot(sm_Fsolo1)
hold on
plot(sm_Fsolo2,'r')
plot(sm_Fsolo3,'k')
legend('Fg1','Fg2','Fg3')
title('Fg')

figure
plot(sm_H2OSolo1)
hold on
plot(sm_H2OSolo2,'r')
plot(sm_H2OSolo3,'k')
legend('us1','us2','us3')
title('usolo')

figure
plot(sm_Tsolo1)
hold on
plot(sm_Tsolo2,'r')
plot(sm_Tsolo3,'k')
legend('Ts1','Ts2','Ts3')
title('Tsolo')

figure
bar(sm_Prec)
title('Prec')

%%%%%%%%%%%Analyses of CO2 and Energy Balance

%%% dados espurios

sm_Rn(find(sm_Rn<-100))=NaN;
sm_Rn(find(sm_Rn>1000))=NaN;
sm_CO2(find(sm_CO2<-50))=NaN;
sm_CO2(find(sm_CO2>20))=NaN;
sm_ustar(find(sm_ustar>15))=NaN;

for i=1:nd*48
 if sm_Rg(i)<1
     if sm_CO2(i)<0
         sm_CO2(i)=NaN;
     end
     
 end
end


% onde cortar CO2 com a turbulencia, ustar
   k=0;
   for i=200*48:300*48
     if sm_Rg(i)<=10 && sm_CO2(i)>=0 && sm_ustar(i)<0.6 && sm_ustar(i)>0.05
           k=k+1;
           uxm(k)=sm_ustar(i);
           CO2mux(k)=sm_CO2(i);
       end
   end
   
   lk=0;
   for h=0.01:0.005:0.6;
       suma=0;
       ji=0;
       lk=lk+1;
   for i=1:k;
       if uxm(i)<h;
           ji=ji+1;
           suma=suma+CO2mux(i);
       end
   end
   uca(lk)=suma/ji;
   end
  
    figure
    plot([0.01:0.005:0.6],uca,'.')
    xlabel('u*(m/s)')
    ylabel('CO_{2} Flux (µmol m^{-2} s^{-1})')
    
 figure
    plot(sm_CO2)
    hold on
  
sm_CO2(find(sm_ustar<0.15))=NaN;
sm_CO2_n=sm_CO2;
    

    plot(sm_CO2_n,'r')
    legend('sem corte u*', 'com corte u* 0.15')
    ylabel('CO_{2} Flux (µmol m^{-2} s^{-1})')
    title('Cruz Alta - com corte u* 0.1')


 %ciclo diario
for i=1:48
    sm_Le_h(i)=nanmean(sm_LE(i:48:48*nd));
    sm_Rn_h(i)=nanmean(sm_Rn(i:48:48*nd));
    sm_H_h(i)=nanmean(sm_H(i:48:48*nd));
    sm_Fg_h(i)=nanmean(sm_Fsolo(i:48:48*nd));
    sm_CO2_h(i)=nanmean(sm_CO2(i:48:48*nd));
    sm_ustar_h(i)=nanmean(sm_ustar(i:48:48*nd));
end
figure
plot(sm_CO2_h)
ylabel('CO_{2} Flux (µmol m^{-2} s^{-1})')
title('Santa  Maria')

figure
plot(sm_ustar_h)
ylabel('u* (m s^{-1})')
title('Santa  Maria')

figure
plot(sm_Le_h)
hold on
plot(sm_H_h,'r')
plot(sm_Fg_h,'k')
plot(sm_Rn_h,'m')
plot(sm_Le_h+sm_H_h+sm_Fg_h,':m')
legend('LE','H','Fg','Rn','Le+H+Fg')
title('Santa  Maria')

 %media diaria
 for i=1:(nd)
    sm_Le_d(i)=nanmean(sm_LE(1+48*(i-1):48+48*(i-1)));
    sm_Temp_d(i)=nanmean(sm_Temp(1+48*(i-1):48+48*(i-1)));
    sm_Rn_d(i)=nanmean(sm_Rn(1+48*(i-1):48+48*(i-1)));
    sm_H_d(i)=nanmean(sm_H(1+48*(i-1):48+48*(i-1)));
    sm_Fg_d(i)=nanmean(sm_Fsolo(1+48*(i-1):48+48*(i-1)));
    sm_CO2_d(i)=nanmean(sm_CO2(1+48*(i-1):48+48*(i-1)));
 end
 figure
subplot(2,2,1)
plot(sm_CO2_d)
legend('CO2')
title('Santa  Maria')
subplot(2,2,2)
plot(sm_Le_d)
legend('Le')
subplot(2,2,3)
plot(sm_H_d)
legend('H')
subplot(2,2,4)
plot(sm_Fg_d)
legend('Fg')

figure
plot(sm_Le_d)
hold on
plot(sm_H_d,'r')
plot(sm_Fg_d,'k')
plot(sm_Rn_d,'m')
legend('LE','H','Fg','Rn')
title('Santa  Maria')

figure
plot(sm_Rn_d+sm_Fg_d,sm_Le_d+sm_H_d,'.k')

figure
subplot(2,2,1)
plot(sm_u)
title('u')
subplot(2,2,2)
plot(sm_v)
title('v')
subplot(2,2,3)
plot(sm_w)
title('w')
subplot(2,2,4)
plot(sm_Ptemp)
title('Ptemp')
 
figure
subplot(2,2,1)
plot(sm_e)
title('e')
subplot(2,2,2)
plot(sm_es)
title('es')
subplot(2,2,3)
plot(sm_VPD)
title('VPD')
subplot(2,2,4)
plot(sm_RH)
title('RH')


figure
subplot(2,2,1)
plot(sm_ustar)
title('ustar')
subplot(2,2,2)
plot(sm_Tstar)
title('Tstar')
subplot(2,2,3)
plot(sm_TKE)
title('TKE')
subplot(2,2,4)
plot(sm_Tau)
title('Tau')
 
figure
subplot(2,2,1)
plot(sm_u_var)
title('u_{var}')
subplot(2,2,2)
plot(sm_v_var)
title('v_{var}')
subplot(2,2,3)
plot(sm_w_var)
title('w_{var}')

figure
subplot(2,2,1)
plot(sm_vento)
title('vento')
subplot(2,2,2)
plot(sm_dirvento)
title('Dirvento')
subplot(2,2,3)
plot(sm_Pmb)
title('Pmb')
subplot(2,2,4)
plot(sm_RH)
title('RH')


