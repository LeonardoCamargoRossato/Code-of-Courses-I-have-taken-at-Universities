PROGRAM rootNEWTON
implicit real*8 (a-h,o-z)

external Fun,DerF

	DL = 1.0E-06
	X0 = 1d0
	ISTEP = 0
	DO 1 WHILE (Abs(Fun(X0))<=DL)
	X1 = X0 - Fun(X0) / DerFanalit(X0) 
	DX = X1 - X0
	X0 = X1

	WRITE (*,*) 'interation =', ISTEP,'x0=',X0,'x0-x1 =',DX,'Fun(x0) =',Fun(x1)
	ISTEP = ISTEP + 1
1	END DO
	
	open(unit=22, file='function.dat')
	do while(i<n)
		write(22, *)i,f(i)
		i = i + 0.05
	close(22)
	
RETURN
END

Real*8 FUNCTION DerFanalit(X)
	implicit real*8 (a-h,o-z)
	h = 0.01d0
	DerFanalit = (Fun(X + h) - Fun(X))/h 
	RETURN
END

Real*8 FUNCTION Fun(x)
	implicit real*8 (a-h,o-z)
	!Fun = x**2.d0 - x - 6.d0
	Fun = EXP(X)*LOG(X) - X**2.d0
	RETURN
END

Real*8 FUNCTION DerF(X)
	implicit real*8 (a-h,o-z)
	DerF = 2.d0*X - 1.d0 !EXP(X)*(LOG(X) + 1.d0/X) - 2.d0*X! 
	RETURN
END
