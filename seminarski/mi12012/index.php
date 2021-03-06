<?php session_start(); ?>

<!DOCTYPE html 
     PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
     "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
	 
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title> autooglasi.rs </title>
		<link rel='icon' type='image/png' href='slike/slikafaviconn.png'/>


		<meta http-equiv="Content-Type" content="text/html; charset=utf-8"></meta>	
		<meta http-equiv="Content-Script-Type" content="text/javascript"></meta>

		<meta name='author' content='Nenad Lazić'></meta>
		<meta name='generator' content='Sublime Text 2'></meta>
		<meta name='description' content='Seminarski rad studenta mi12012 iz predmeta Uvit'></meta>
		<meta name='keywords' content='Nenad Lazić,uvit,seminarski,2014,matf'></meta>
		<meta name='language' content='SR'></meta>
		
		<!--CSS-->
		<link rel='stylesheet' type='text/css' href='css/stil.css'/>
		
		<!--JS-->
		<script src='javascript/skripte.js' type='text/javascript'></script>
		<script src='javascript/skripte2.js' type='text/javascript'></script>		
		<script src='javascript/jquery.js' type='text/javascript'></script>
		
		<!--PHP-->
		<?php 
			include('inc/header.inc'); // Funkcije vezane za header stranica
			include('inc/nav.inc'); // Funkcije vezane za navigaciju stranica
			include('inc/content.inc'); // Funkcije vezane za sadrzaj stranica
			include('inc/footer.inc'); // Funkcije vezane za footer stranica
		?>		
	</head>

	<body lang='SR' onload='ajaxPozivi(); checkCookie();'>
		<div id="omotac">
			<?php drawHeader(); // Iscrtavanje header-a ?>
			<?php drawNav(); // Iscrtavanje navigacije ?>
			<?php drawContent(); // Iscrtavanje content-a ?>
			<?php drawFooter(); // Iscrtavanje footer-a ?>
			<?php include 'logInOut.php'; //ukljucujemo kod za realizaciju login i logout?>
			<?php include 'pretraga_oglasa_u_bazi.php'; //php za pretragu baze po zadatim kriterijumima korisnika
			?>
 		</div>
	</body>
</html>