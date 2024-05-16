PROGRAM rootNEWTON
implicit real*8 (a-h,o-z)

external Fun,DerF
DL = 1.0E-06
X0 = 0.5d0
ISTEP = 0
DO 1 WHILE (Abs(Fun(X0)).GT.DL)
X1 = X0 - Fun(X0)/DerF(X0)
DX = X1 - X0
X0 = X1
WRITE (*,*) 'interation =', ISTEP,'x0=',X0,'x0-x1=',Dx,'Fun(x0) = ',Fun(x1)
ISTEP = ISTEP + 1
END DO
! WRITE(*,*) 'One root is',x0
RETURN
END

Real*8 FUNCTION Fun(x)
implicit real*8 (a-h,0-z)
Fun = x**2.d0 - x - 6.d0!EXP*LOG(X) - X*X!
RETURN
END

Real*8 FUNCTION DerF(X)
implicit real*8 (a-h,o-z)
DerF = EXP(X)*(LOG(X) + 1.d0/X) - 2.d0*X!2.d0*x - 1.d0!
RETURN
END
