PROGRAM calculo_massa2
	implicit none
	Real*8 x,a,b,w,x1,dl,func,istep
	Real*8 M,m0,intgr,pi
	external func 
	
	a = 0.001d0
	b = 0.5d0
	dl = 1.0E-09
	istep = 0
	w = 0.05d0	
	write(*,*) 'w:', w , 'func(w):', func(w)
	 
Do while (abs(func(w)) > dl)
	write(*,*) 'hi - '
	w = (a + b)/2
	x = func(a) * func(w)
	
	if(x < 0) then
		b = w
	else
		a = w
	end if
	istep = istep + 1
	
	write(*,*) 'a=', a, 'b=', b, 'w=', w,'x=',x, 'Uma Raiz e:',w,'passos', istep
end do
	
	write(*,*) 'hi 2'
END PROGRAM calculo_massa2

!##########################################################

Real*8 FUNCTION func(M)
	implicit none 
	real*8 x,m0,nc,nf,g,xint,M,pi,funcao,x_inf,x_sup
	integer passos
	
	write(*,*) 'dentro da func(M)' 
	
	passos = 100000
	pi = 4.d0*datan(1.d0)
	nc = 3.d0
	nf = 2.d0
	m0 = 0.0056d0
	x_sup = 0.5879d0
	g = 2.44d0/(x_sup**2.d0)
	x_inf = 0.d0
	Call integration_aula(x_sup,x_inf,passos,xint,M) !(arg1 = limite superior, arg2 = lim.inf)
	funcao = M - m0 - ((2.d0*g*nc*nf*M)/(pi**2.d0)) * xint
!	funcao = M - m0 - ((17.167d0*M)/(2.d0)) * intgr
	return
END FUNCTION	

!##########################################################

SUBROUTINE integration_aula(x_sup,x_inf,passos,xint,M) 
	implicit none
	
	real*8 x_sup,x_inf
	integer passos 
	real*8 xint, M
	real*8 xmax, xmin, integracao, h,fun !,t1,t2
	integer n,j
	external fun
	
!	CALL CPU_TIME(t1)
	
	n = passos !Numero de passos 
	xmax = x_sup !limite superior integral
	xmin = x_inf !limite inferior integral
	integracao = 0.d0
	h = (xmax - xmin)/n   !largura do passo de integracao
	
	do j = 2,(n - 1)
		integracao = integracao + fun(xmin + j*h,M)
	end do
	
	xint = h*(integracao + 0.5d0*(fun(0.d0,M) + fun(x_sup, M)))
	
!	CALL CPU_TIME(t2)
	
!	write(*,*)
!	write(*,*) 'timer integration:' , (t2-t1)
!	write(*,*)
	
	return	
END SUBROUTINE integration_aula

!##########################################################

Real*8 FUNCTION fun(x,M)
	implicit none
	real*8 x,M
	fun = x**2.d0 / dsqrt(x**2.d0 + M**2.d0)
	return
END FUNCTION

!##########################################################

