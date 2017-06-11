<?php 
	function drawFooter()
	{
		echo "	
			
			<div id='podnozje'>
				<div id='ufooteru'>
					<p> copyright &copy; 2014 
					<span style='color:#FF6600'>design  </span> 
					nenad
					&nbsp; &nbsp;
					</p>
				</div>
				<div id='zaAjax'>
					<form name='mojaForma'>	
						Vreme: <input type='text' name='vreme' size='5' />
					</form>
				</div>
				<div id='zaCookie' onclick='checkCookie1();'>
					Korisnička podešavanja
				</div>
				<div id='zaCookiee' onclick='clearCookie();'>
					Obriši kolačiće
				</div>			
			</div>
			";
	}
?>