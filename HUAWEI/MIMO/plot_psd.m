function plot_psd(x,Nfft,Fs)
    [spectra,freq]=pwelch(x,hann(Nfft),[],Nfft,Fs,'centered');
    plot(freq,10*log10(spectra));
  end