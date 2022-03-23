clc
close all
%% load data
load ./Simulation_MPDPD_Data.mat
%% params
Nfft = 1024;
M = 3;
P = 5;
c = zeros(1,M*(ceil(P/2)));
c(1,1) = 1;
N_iter = 2000;
mu = 0.5e-1;
%% gain align
Nx = size(x,2);
d = d*sqrt(mean(abs(x).^2)/mean(abs(d).^2));
%% plot
figure;
plot(abs(x),'.-b');
hold on;
plot(abs(d),'.-r');
legend('x','d');
figure;
plot_psd(x,Nfft,Fs);
hold on;
plot_psd(d,Nfft,Fs);
xlabel('Hz');
ylabel('dB');
legend('x','d');

%% Vand Matrix contruction
V = MP_Vand(x,M,P);
%% get predistortion output
y_arr = c*V;
Origin_NMSE_dB = 10*log10(mean(abs(y_arr(M:Nx)-d(M:Nx)).^2)/mean(abs(d(M:Nx)).^2));
%% iteration for
e_arr = zeros(1,Nx);
for n=1:N_iter
    for i=M:Nx
        %% get MP output
        y = c*V(:,i);
        %% get error
        e = d(i)-y;
        e_arr(i) = e;
        %% LMS update
        c = c + mu*e*conj(transpose(V(:,i)));
    end
    if mod(n,100)==1 
        %% get predistortion output
        y_arr = c*V;
        AfMPDPD_NMSE_dB = 10*log10(mean(abs(y_arr(M:Nx)-d(M:Nx)).^2)/mean(abs(d(M:Nx)).^2));
        fprintf("Iteration %d, Origin_NMSE = %.2f dB, AfMPDPD_NMSE = %.2f dB, Optimalization = %.2f dB.\n",n,Origin_NMSE_dB,AfMPDPD_NMSE_dB,Origin_NMSE_dB-AfMPDPD_NMSE_dB);
    end
end
%% get predistortion output
y_arr = c*V;
AfMPDPD_NMSE_dB = 10*log10(mean(abs(y_arr(M:Nx)-d(M:Nx)).^2)/mean(abs(d(M:Nx)).^2));
pd = x - y_arr + d;
%% plot
figure;
plot(abs(e_arr),'.-b');
legend('LMS err');
figure;
plot(abs(x(M:Nx)),'.-b');
hold on;
plot(abs(d(M:Nx)),'.-r');
legend('x','d');
figure;
plot_psd(x(M:Nx),Nfft,Fs);
hold on;
plot_psd(d(M:Nx),Nfft,Fs);
plot_psd(pd(M:Nx),Nfft,Fs);
xlabel('Hz');
ylabel('dB');
legend('x','d','with MPDPD');
fprintf("Origin_NMSE = %.2f dB, AfMPDPD_NMSE = %.2f dB, Optimalization = %.2f dB.\n",Origin_NMSE_dB,AfMPDPD_NMSE_dB,Origin_NMSE_dB-AfMPDPD_NMSE_dB);


