-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Aug 21, 2014 at 08:33 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `autooglasi`
--

-- --------------------------------------------------------

--
-- Table structure for table `kontakt`
--

CREATE TABLE IF NOT EXISTS `kontakt` (
  `idOglasa` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `mail` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `telefon` varchar(15) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`idOglasa`,`mail`),
  KEY `mail` (`mail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `kontakt`
--

INSERT INTO `kontakt` (`idOglasa`, `mail`, `telefon`) VALUES
('kor1o1', 'korisnik1@gmail.com', '0142588888'),
('kor2o1', 'kor2@gmail.com', '014789654'),
('kor3o1', 'kor3@gmail.com', '014258852'),
('kor4o1', 'kor4@gmail.com', '0601234567'),
('kor5o1', 'kor5@gmail.com', '014646151'),
('kor6o1', 'kor6@gmail.com', '06456789'),
('kor7o1', 'kor7@gmail.com', '0657894561'),
('kor8o1', 'kor8@gmail.com', '014789654');

-- --------------------------------------------------------

--
-- Table structure for table `korisnici`
--

CREATE TABLE IF NOT EXISTS `korisnici` (
  `idKorisnika` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `ime` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `prezime` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `sifra` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `mail` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`idKorisnika`,`mail`),
  UNIQUE KEY `idKorisnika` (`idKorisnika`),
  UNIQUE KEY `mail` (`mail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `korisnici`
--

INSERT INTO `korisnici` (`idKorisnika`, `ime`, `prezime`, `sifra`, `mail`) VALUES
('kor1', 'korisnik1ime', 'korisnik1prezime', '91cd29f75a38106adbb4', 'korisnik1@gmail.com'),
('kor2', 'kor2ime', 'kor2prezime', '91cd29f75a38106adbb4', 'kor2@gmail.com'),
('kor3', 'kor3ime', 'kor3prezime', '91cd29f75a38106adbb4', 'kor3@gmail.com'),
('kor4', 'kor4ime', 'kor4prezime', '91cd29f75a38106adbb4', 'kor4@gmail.com'),
('kor5', 'kor5ime', 'kor5prezime', '91cd29f75a38106adbb4', 'kor5@gmail.com'),
('kor6', 'kor6ime', 'kor6prezime', '91cd29f75a38106adbb4', 'kor6@gmail.com'),
('kor7', 'kor7ime', 'kor7prezime', '91cd29f75a38106adbb4', 'kor7@gmail.com'),
('kor8', 'kor8ime', 'kor8prezime', '91cd29f75a38106adbb4', 'kor8@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `lokacijeslika`
--

CREATE TABLE IF NOT EXISTS `lokacijeslika` (
  `idOglasa` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `lokacija` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`idOglasa`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `lokacijeslika`
--

INSERT INTO `lokacijeslika` (`idOglasa`, `lokacija`) VALUES
('kor1o1', 'images/1408644627435361116AudiA4.jpg'),
('kor2o1', 'images/1408645254321140647audicijaKontakt.jpg'),
('kor3o1', 'images/1408645473239714115logoaud.jpg'),
('kor4o1', 'images/14086455751104995456AudiA4.jpg'),
('kor5o1', 'images/1408645641206308271audicijaKontakt.jpg'),
('kor6o1', 'images/14086457211989545626slika4.jpg'),
('kor7o1', 'images/1408645777729906375slika5.jpg'),
('kor8o1', 'images/14086458331349216577pozadinaZaReg2.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `oglasi`
--

CREATE TABLE IF NOT EXISTS `oglasi` (
  `idOglasa` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `idKorisnika` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `karoserija` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `kubikaza` int(4) NOT NULL,
  `godiste` int(4) NOT NULL,
  `cena` int(7) NOT NULL,
  `region` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `gorivo` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `registrovan` varchar(2) COLLATE utf8mb4_unicode_ci NOT NULL,
  `tekstOglasa` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL,
  `marka` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`idOglasa`,`idKorisnika`),
  UNIQUE KEY `idOglasa` (`idOglasa`),
  KEY `idKorisnika` (`idKorisnika`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `oglasi`
--

INSERT INTO `oglasi` (`idOglasa`, `idKorisnika`, `karoserija`, `kubikaza`, `godiste`, `cena`, `region`, `gorivo`, `registrovan`, `tekstOglasa`, `marka`) VALUES
('kor1o1', 'kor1', 'Limuzina', 2000, 2002, 2002, 'Zapadna Srbija', 'dizel', 'da', 'prodajem auto', 'audi'),
('kor2o1', 'kor2', 'Limuzina', 2000, 2000, 2000, 'Zapadna Srbija', 'dizel', 'da', 'prodajem auto u odlicnom stanju.', 'audi'),
('kor3o1', 'kor3', 'Limuzina', 2000, 2000, 2000, 'Zapadna Srbija', 'dizel', 'da', 'prodajem auto u odlicnom stanju garaziran.', 'audi'),
('kor4o1', 'kor4', 'Limuzina', 2500, 2007, 7500, 'Zapadna Srbija', 'dizel', 'da', 'prodajem auto. crna boja, zatamljena stakla, tuning...za sve info na tel...', 'audi'),
('kor5o1', 'kor5', 'Limuzina', 2200, 2005, 3500, 'Zapadna Srbija', 'dizel', 'da', '', 'audi'),
('kor6o1', 'kor6', 'Limuzina', 2400, 2004, 6000, 'Zapadna Srbija', 'dizel', 'da', 'auto je lep', 'audi'),
('kor7o1', 'kor7', 'Limuzina', 2000, 2000, 2000, 'Zapadna Srbija', 'dizel', 'da', 'auto je prelep', 'audi'),
('kor8o1', 'kor8', 'Limuzina', 2400, 2005, 7500, 'Zapadna Srbija', 'dizel', 'da', 'auto je dobro ocuvan.', 'audi');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `kontakt`
--
ALTER TABLE `kontakt`
  ADD CONSTRAINT `kontakt_ibfk_1` FOREIGN KEY (`idOglasa`) REFERENCES `oglasi` (`idOglasa`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `kontakt_ibfk_2` FOREIGN KEY (`mail`) REFERENCES `korisnici` (`mail`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `lokacijeslika`
--
ALTER TABLE `lokacijeslika`
  ADD CONSTRAINT `lokacijeslika_ibfk_1` FOREIGN KEY (`idOglasa`) REFERENCES `oglasi` (`idOglasa`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `oglasi`
--
ALTER TABLE `oglasi`
  ADD CONSTRAINT `oglasi_ibfk_1` FOREIGN KEY (`idKorisnika`) REFERENCES `korisnici` (`idKorisnika`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
