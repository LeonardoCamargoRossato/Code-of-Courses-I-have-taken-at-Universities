Program sistema_eqs_lineares
implicit none

	integer :: i,j,k,n
	parameter (n=3) !Macro
	Real :: x(n),c

!REAL :: a(3,3) = RESHAPE((/3.0,2.0,1.0,2.0,-3.0,1.0,4.0,1.0,2.0/),(/3,3/))
!REAL :: b(3,1) = RESHAPE((/4.0,2.0,3.0/),(/3,1/))

	Real  a(3,3) /3.0d0, 2.0d0 ,1.0d0, 2.0d0, -3.0d0, 1.0d0, 4.0d0, 1.0d0 , 2.0d0/
	Real  b(3) /4.0d0, 2.0d0 , 3.0d0 /

!	Real  a(2,2) /3.0d0, 2.0d0 ,1.0d0, 2.0d0/
!	Real  b(2) /4.0d0, 2.0d0 /

!Aqui escreve as eq na tela

Write(*,*)
Write(*,*) 'Aqui mostra o Sistema a Ser Resolvido' 
Write(*,*)

!	do i=1, 3
!		do j=1, 3
!			write(*,*) a(i,j) 
!		end do
!		Write(*,*)
!	end do
	
	do i=1, 3
		write(*,*) a(i,1), a(i,2), a(i,3)  
		Write(*,*)
	end do


!Função 1
	do k=1, n-1
		do i=k+1,n
		c = a(i,k) / a(k,k)
		a(i,k) = 0.0
		b(i) = b(i) - c*b(k)
		do j=k+1,n
		a(i,j) = a(i,j)-c*a(k,j)
		end do
	end do
	end do


!Função 2
	x(n) = b(n) / a(n,n)
	
	do i=n-1,1,-1
	c = (0,0)
		do j=i+1,n
		c = c + a(i,j)*x(j)
		end do
	x(i) = (b(i) - c) / a(i,i)
	end do
	
Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui Mostra a Solução do Sistema'
Write(*,*) '############################################'
Write(*,*)

!	write(*,*) x(1),x(2),x(3)
	write(*,*) 'x(1) =', x(1), 'x(2) =', x(2),'x(3) =', x(3)

end program
