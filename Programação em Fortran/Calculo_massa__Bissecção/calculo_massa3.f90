PROGRAM calculo_massa3
	implicit none
	Real*8 x,a,b,dl,w,func
	Integer istep
	external func 
	
	a = 0.001d0
	b = 0.5d0
	dl = 1.0E-09
	istep = 0
	
 	Call plota_grafico() 
	
	!Cálculo da Raiz da Equação - Método Bissecção
	Do while (abs(func(w)) > dl)		
		w = (a + b)/2
		
		x = func(a) * func(w)
		if(x < 0) then
			b = w
		else
			a = w
		end if	
		istep = istep + 1
		
		!Coloquei esse If só pra diminuir o número de passos mostrados na tela (só vão aparecer os passos pares)
		if (MOD(istep,2) == 0) then 
			write(*,*) 'a=', a, 'b=', b, 'w=', w,'x=',x, 'Raiz:',w,'Passo:', istep
		end if
	End do

END PROGRAM calculo_massa3

!##########################################################

Real*8 FUNCTION func(M)
	implicit none 
	real*8 x,m0,nc,nf,L,g,M,intgr,pi
	
	pi = 4.d0*datan(1.d0)
	m0 = 0.0056d0
	nc = 3.d0
	nf = 2.d0
	L = 0.5879d0
	g = 2.44d0/(L**2.d0)
	
	Call integration_aula(M,L,intgr) 
	func = M - m0 - ((2.d0*g*nc*nf*M)/(pi**2.d0)) * intgr

	return
END FUNCTION	

!##########################################################

SUBROUTINE integration_aula(M,L,intgr) 
	implicit none
	real*8 xmax,xmin,tempT,h,M,L,fun,intgr
	integer n,j
	external fun
	
	n = 100000 !Numero de passos 
	xmax = L !limite superior integral
	xmin = 0.d0 !limite inferior integral
	tempT = 0.d0
	h = (xmax - xmin)/n   !largura do passo de integracao
	
	do j = 2,(n - 1)
		tempT = tempT + fun(xmin + j*h,M)
	end do
	
	intgr = h*(tempT + 0.5d0*(fun(0.d0,M) + fun(L, M)))
		
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

SUBROUTINE plota_grafico() 
	implicit none
	real*8 M,Mmin,Mmax,Xlambda,h,F,m0,L,g,nc,nf,pi,intgr
	integer j,n

	pi = 4.d0*datan(1.d0)
	m0 = 0.0056d0
	L = 0.0056d0
	nc = 3
	nf = 2
	xlambda = 0.5879d0
	g = 2.44d0/(xlambda**2.d0)

	Mmin = 0.001d0
	Mmax = 1d0
	n = 25
	h = (Mmax - Mmin)/dfloat(n - 1) !largura do passo de integracao (ou largura do trapézio)

	open(unit=25, file='FXM')
	do j = 1,n
		M = Mmin + dfloat(j-1)*h
		Call integration_aula(M,L,intgr)  ! Argumentos Func = inputs + outputs
		F = M - m0 - ((2.d0*g*nc*nf*M)/(pi**2.d0)) * intgr
		write(*,*) 'M=',M,'F(M)=', F
		write(25,*)M, F
	end do
	close(25)
	!-----------------------------------------------------------------------------------------------

	call system('gnuplot -p FXM.plt') !Comando Simples pra Plotar Gnuplot de Dentro do Fortran (OBS* Só vale pra Linux)
	
	write(*,*)
	write(*,*) '##################################################'
	write(*,*)
	return	
END SUBROUTINE plota_grafico

