/* funkcija proverava unos korisnika iz forme za pretragu oglasa po kriterijumima koje
korisnik zadaje. Korisnik mora da unese marku, karoseriju automobila, granice kubikaze motora itd */

function proveriFormuPretrage()
{
	var i = document.getElementsByName('proizvodjac')[0].selectedIndex;
	if( i == 0){
		window.alert('Niste odabrali marku automobila! Pokušajte ponovo.');
		document.getElementsByName('proizvodjac')[0].focus();
		return false;}
	else{
		var j = document.getElementsByName('karoserija')[0].selectedIndex;
		if(j == 0){
			window.alert('Niste odabrali karoseriju automobila! Pokušajte ponovo.');
			document.getElementsByName('karoserija')[0].focus();
			return false;}
		else{
			var kubod, kubdo;
			kubod = document.getElementsByName('kubikaOd')[0].selectedIndex;
			kubdo = document.getElementsByName('kubikaDo')[0].selectedIndex;
			
			if(kubod == 0){
				window.alert('Niste uneli donju granicu kubikaze motora! Pokušajte ponovo.');
				document.getElementsByName('kubikaOd')[0].focus();
				return false;}
			else
				if(kubdo == 0){
					window.alert('Niste uneli gornju granicu kubikaze motora! Pokušajte ponovo.');
					document.getElementsByName('kubikaDo')[0].focus();
					return false;}
					else{
						if(kubod >= kubdo){
							window.alert('Ne postoji vozilo sa zadatim rasponom kubikaže. Pokušajte ponovo.');
							document.getElementsByName('kubikaDo')[0].focus();
							return false;}
						else{
								var godod, goddo;
								godod = document.getElementsByName('godisteOd')[0].selectedIndex;
								goddo = document.getElementsByName('godisteDo')[0].selectedIndex;
											
								if(godod == 0){
									window.alert('Niste uneli donju granicu za godiste vozila! Pokušajte ponovo. ');
									document.getElementsByName('godisteOd')[0].focus();
									return false;}
								else
									if(goddo == 0){
										window.confirm('Niste uneli gornju granicu za godiste vozila! Pokušajte ponovo.');
										document.getElementsByName('godisteDo')[0].focus();
										return false;}
									else{
										if(godod >= goddo){
											window.alert('Ne postoji vozilo proizvedeno u zadatom periodu. Pokušajte ponovo.');
											document.getElementsByName('godisteDo')[0].focus();
											return false;}
										else{
											var kostaOd,kostaDo;
											
											if(document.getElementsByName('cenaOd')[0].value == 'od' || document.getElementsByName('cenaDo')[0].value == 'do')
											{
											window.alert('Morate postaviti granice cene. Pokušajte ponovo.');
											document.getElementsByName('cenaOd')[0].focus();
											return false;											
											}
											kostaOd = parseInt(document.getElementsByName('cenaOd')[0].value);
											kostaDo = parseInt(document.getElementsByName('cenaDo')[0].value);
											
								
											if(kostaOd <0 || kostaDo <=0 || kostaOd >= kostaDo){
												window.alert('Ne postoji vozilo sa zadatom cenom. Granice cene moraju biti pozitivni brojevi i od < do. Pokušajte ponovo.');
												document.getElementsByName('cenaOd')[0].focus();
												return false;}
												else{
													var k = document.getElementsByName('region')[0].selectedIndex;
													if( k == 0){
														window.alert('Niste odabrali region. Pokušajte ponovo.');
														document.getElementsByName('region')[0].focus();
														return false;}
														else{
															for(var l = 0; l < document.getElementsByName('gorivo').length; l++)
																if(document.getElementsByName('gorivo')[l].checked)
																	break;
																	
																if( l == 3){
																	window.alert('Niste odabrali vrstu goriva. Pokušajte ponovo.');
																	document.getElementsByName('gorivo')[1].focus();
																	return false;}
																	else
																		if(!(document.getElementById('registrovannno').checked) && !(document.getElementById('neregistrovannno').checked))
																		{
																			window.alert('Potrebno je da cekirate trenutno stanje registracije vozila. Pokušajte ponovo.');
																			return false;
																		}
																
															}
														
													}
											}
										}
										
							}
						}
			}
		}
	
}

function proveriFormuLogovanja()
{
	if(document.getElementsByName('username')[0].value == 'ovde unesite username' ||
		document.getElementsByName('username')[0].value == '')
	{
		window.alert('Niste uneli username. Pokusajte ponovo.');
		document.getElementsByName('username')[0].focus();
		return false;
	}
	else
		if(document.getElementsByName('sifra')[0].value == ''){
			window.alert('Niste uneli password. Pokusajte ponovo.');
			document.getElementsByName('sifra')[0].focus();
			return false;
		}
}

function proveriFormuRegistracije(){
		var ime = document.getElementsByName('imeKorisnika')[0].value; 
		if(ime == "" || ime.charCodeAt(0) < 65 || ime.charCodeAt(0) >122 || (ime.charCodeAt(0) > 90 && ime.charCodeAt(0) < 97) ){
			window.alert("Neispravno ime (mora se sastojati uz nepraznog stringa i mora počinjati slovom)");
			document.getElementsByName('imeKorisnika')[0].focus();
			return false;
		}

		var prezime = document.getElementsByName('prezimeKorisnika')[0].value; 
		if(prezime == "" || prezime.charCodeAt(0) < 65 || prezime.charCodeAt(0) >122 || (prezime.charCodeAt(0) > 90 && prezime.charCodeAt(0) < 97) ){
			window.alert("Neispravno prezime (mora se sastojati uz nepraznog stringa i mora počinjati slovom)");
			document.getElementsByName('prezimeKorisnika')[0].focus();
			return false;
		}

		var imeNaSajtu = document.getElementsByName('imeNaSajtu')[0].value; 
		if(imeNaSajtu == "" || imeNaSajtu.length >8 || imeNaSajtu.charCodeAt(0) < 65 || imeNaSajtu.charCodeAt(0) >122 || (imeNaSajtu.charCodeAt(0) > 90 && imeNaSajtu.charCodeAt(0) < 97) ){
			window.alert("Neispravno ime na sajtu (mora se sastojati uz nepraznog stringa, mora počinjati slovom i mora biti maximalno 8 karaktera duzine)");
			document.getElementsByName('prezimeKorisnika')[0].focus();
			return false;
		}


		if(document.getElementsByName('emailKorisnika')[0].value == ""){
			window.alert("Niste uneli e-mail. Pokušajte ponovo.");
			document.getElementsByName('emailKorisnika')[0].focus();
			return false;
		}
		
		var sif1 = document.getElementsByName('sifrica')[0].value;
		var sif2 = document.getElementsByName('sifricaOpet')[0].value;
		
		if(sif1 != sif2 || sif1 == "" || sif1.length < 6){
			window.alert('Neispravna lozinka.');
			document.getElementsByName('sifrica')[0].select();
			document.getElementsByName('sifricaOpet')[0].value = "";			
			return false;
		}
		window.alert('Ispravno ste popunili formular. Sacekajte izvestaj o registraciji!');
}

function proveriFormuPoruke(){
	var poruka = document.getElementsByName('porukica')[0].value;
	var duzinaporuke = poruka.length;
	if( duzinaporuke < 3){
		window.alert('Poruka mora imati 3 i više karaktera! Pokušajte ponovo.');
		document.getElementsByName('porukica')[0].focus();
		return false;
	}

	var eadresa = document.getElementsByName('mailkorisnika')[0].value;
	if(eadresa.length < 5){
		window.alert('Nekorektna mail adresa za odgovor! Pokušajte ponovo.');
		document.getElementsByName('mailkorisnika')[0].focus();
		return false;		
	}
}


	tday  =new Array('Nedelja','Ponedeljak','Utorak','Sreda','Četvrtak','Petak','Subota');
	tmonth=new Array('Januar','Februar','Mart','April','Maj','Jun','Jul','Avgust','Septembar','Oktobar','Novembar','Decembar');

function proveriFormuUpisa(){
	

	var i = document.getElementsByName('proizvodjacc')[0].selectedIndex;
	if( i == 0){
		window.alert('Niste odabrali marku automobila! Pokušajte ponovo.');
		document.getElementsByName('proizvodjacc')[0].focus();
		return false;
	}
	else{
		var j = document.getElementsByName('karoserijaa')[0].selectedIndex;
		if(j == 0){
			window.alert('Niste odabrali karoseriju automobila! Pokušajte ponovo.');
			document.getElementsByName('karoserijaa')[0].focus();
			return false;
		}
		else{
			var kub;
			kub = document.getElementsByName('kubikaa')[0].value;

			if(kub < 500 || kub > 3000){
				window.alert('Niste uneli ispravnu kubikazu motora(mora biti izmedju 500 i 3000)! Pokušajte ponovo.');
				document.getElementsByName('kubikaa')[0].focus();
				return false;
			}
			else
			{
				var god;
				god = document.getElementsByName('godistee')[0].value;

				if(god < 1970 || god > 2014){
					window.alert('Niste uneli ispravno godiste(mora biti izmedju 1970 i 2014) ! Pokušajte ponovo.');
					document.getElementsByName('godistee')[0].focus();
					return false;
				}
				else
				{
					var cen;
					cen = document.getElementsByName('cenaa')[0].value;

					if(cen < 1 || cen > 1000000){
						window.alert('Niste uneli ispravnu cenu! Cene su od 1 do 1000000! Pokušajte ponovo.');
						document.getElementsByName('cenaa')[0].focus();
						return false;
					}
					else
					{
						var k = document.getElementsByName('regionn')[0].selectedIndex;
						if( k == 0){
						window.alert('Niste odabrali region. Pokušajte ponovo.');
						document.getElementsByName('regionn')[0].focus();
						return false;
						}
						else
						{
							if(!(document.getElementById('registrovann').checked) && !(document.getElementById('neregistrovann').checked))
							{
								window.alert('Potrebno je da cekirate trenutno stanje registracije vozila. Pokušajte ponovo.');
								return false;
							}
				
						}
					}

				}	
			}

		}
	}
}