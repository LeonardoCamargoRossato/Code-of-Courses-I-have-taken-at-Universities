Program troca_coluna
	implicit none
	real T(35),Jx(35)
	integer i
!	integer in,out

	open(1,file='Diagram_U2+AF2_Paramag2',status='old')
	open(2,file='Diagram_U2+AF2_Paramag-out',status='unknown')
	do i=1,35
		read(1,100) Jx(i), T(i)
		100	format(F13.6,F8.6)
	end do
	do i=1,35
		write(2,200) T(i), Jx(i)
		200	format(F8.6,F13.6)
	end do


End Program
