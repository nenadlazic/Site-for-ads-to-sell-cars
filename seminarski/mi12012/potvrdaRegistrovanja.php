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
	</head>

	<body lang='SR'>
		<div id="omotac">
	
			<div id='potvrdaRegistrovanja'>
				<p> Uspešno ste se registrovali na sajt autooglasi.rs </p>
				<p>Možete se ulogovati na sledećoj strani </p>
				<form action='' method='post'>
					<input type='submit' name='procitaoPoruku' value='OK'/>
				</form>
			
				<?php
					if(isset($_POST['procitaoPoruku'])){
						header ('Location: index.php?rsucc=Registration success!'); //sa ovim vrsimo redirekciju na zeljenu php stranu
					}
				?>
			</div>
		</div>
	</body>
</html>
