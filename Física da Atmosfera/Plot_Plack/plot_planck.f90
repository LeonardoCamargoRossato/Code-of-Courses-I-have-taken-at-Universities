program plot_planck
	implicit none
	real*8 a1,a2,l,C1,i
	real*8 T_Terra,planck,expo,arg_exp
	real*8 T_Sol,planck2,expo2,arg_exp2
	
  a1 = 3.75d0*1.0e-16
	a2 = 1.44d0*1.0e-2
  T_Terra = 280.d0
  T_Sol = 5800.d0
  i = 0.01d0
  l = 1.0e-6
  do while (i <= 50)
		C1 = a1/((i**5)*(l**5))
		arg_exp = a2/((i*l)*T_Terra)
		arg_exp2 = a2/((i*l)*T_Sol)
		expo = exp(arg_exp - 1)
		expo2 = exp(arg_exp2 - 1) 
		planck = C1 / expo 
		planck2 = C1 / expo2 
  	print*, i,planck
  	write(101,*) i,planck
  	write(102,*) i,planck2
  	i = i + 0.0001d0
  end do 
end program
