<?php 
	function drawNav()
	{
		echo "	
			
			<div id='meni'>
				<table>
					<tr>
						<th class='navi' id='navi1' onmouseover='anim1()'> <a href='index.php'> Početna </a> </th>
						<th class='navi' id='navi2' onmouseover='anim2()'> <a href='2.php'> Registruj se </a></th>
						<th class='navi' id='navi3' onmouseover='anim3()'> <a href='3.php'> Postavi oglas </a></th>
						<th class='navi' id='navi4' onmouseover='anim4()'> <a href='4.php'> Zanimljivosti </a></th>
						<th class='navi' id='navi5' onmouseover='anim5()'> <a href='5.php'> Kontakt </a></th>
					</tr>
				</table>
			</div>
			";
	}
?>