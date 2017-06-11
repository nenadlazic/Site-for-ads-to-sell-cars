<?php
	$ime_hosta = "localhost"; 

	$korisnickoIme = "root";  

	$sifra = "root";  

	$ime_baze = "autooglasi"; 


	$veza=mysqli_connect("$ime_hosta","$korisnickoIme","$sifra","$ime_baze") or die("Greska prilikom povezivanja sa bazom" . mysqli_error($veza));

	mysqli_set_charset($veza, 'utf8'); //postavlja podrazumevani klijentski charset
?>