<?php 
	function drawHeader()
	{
	echo	"<div id='zaglavlje'>
				<div id='slideshow'>
					<img src='slike/slika1a.jpg' alt='slika nije pronadjena' id='slika' width='1000' height='100'/> 
					<script type='text/javascript'>
						menjajSlike();
					</script>
				</div>
				<div id='formaZaLogoutt'>
					<form method='post' name='formaZaLogout'> 
						<input type='submit' name='logout' value='Izloguj se'/> 
					</form
				</div>
			</div>
			";
	}
?>