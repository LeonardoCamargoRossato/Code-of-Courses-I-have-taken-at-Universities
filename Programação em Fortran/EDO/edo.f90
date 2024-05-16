program edof90
!
implicit none
REAL*8 y,h, t
REAL*8 k1
REAL*8 exata, erro
INTEGER i,n
open(unit=10,file = 'edo2_EULER')
open(unit=11,file = 'edo2_analytic')
t = 0.0d0
y = 8.0d0
h = 0.1d0
n = 100
DO i=1,n,1
	k1 = 2.0d0 + t - 0.5d0*y
	y  = y + h*k1
	exata = 8.0d0*exp(-t/2.d0) + 2.d0*t
	write(*,*)t,y,exata
	write(10,*) t, y	
	write(11,*) t, exata
	t=t+h
ENDDO
close(10)
close(11)
!call execute_command_line('gnuplot -p template.gnu')
!call system('gnuplot -p plot edo2_EULER.dat')
call system('gnuplot -p edo2_EULER.plt')

STOP
END
