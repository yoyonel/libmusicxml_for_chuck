<img src="http://www.franckgraziano.com/wp-content/uploads/2012/11/guitar_pro_icon.png" alt="alt text" height="128">
=> ![Sheet-MusicXML](http://libmusicxml.sourceforge.net/imgs/scorel1.gif) => <img src="https://upload.wikimedia.org/wikipedia/commons/6/6a/ChucK_logo2.jpg" alt="alt text" height="128">
# lib **XMLMusic** pour export vers **Chuck**

Tweak de la lib MusicXml pour un export vers ChucK.
Utilisation du sample xml2midi pour écrire une version pour ChucK (xml2chuck).

C'est assez sommaire en fonctionnalités, mais c'est un start pour l'établissement d'un pipeline permettant d'éditer/export depuis **Guitar Pro** (ou autre éditeurs) vers un format standard XML-**MusicXML** puis vers un "format" propriétaire (ou export code) vers **ChucK**

# The MusicXML Library
![MusicXML](http://dorienherremans.com/sites/default/files/styles/medium/public/field/image/MM_HomePage_XML2.png?itok=s0-OVifk)

The libMusicXML project aims at developping a platform independant library that supports the MusicXML format. The programming language is C/C++. Other languages (like Java, Lisp...) could be supported using dedicated interface files.

* Site web: [http://libmusicxml.sourceforge.net/](http://libmusicxml.sourceforge.net/)
* Project on Source Forge: [http://sourceforge.net/projects/libmusicxml/](http://sourceforge.net/projects/libmusicxml/)

C'est multi-plateformes et open source.
C'est en C++, faudrait regarder pour un bind en Python (à réaliser).

# ChucK
![Chuck](https://upload.wikimedia.org/wikipedia/commons/6/6a/ChucK_logo2.jpg)

[Page Wiki](https://en.wikipedia.org/wiki/ChucK): *ChucK is a concurrent, strongly timed audio programming language for real-time synthesis, composition, and performance,[2] which runs on Linux, Mac OS X, Microsoft Windows, and iOS. It is designed to favor readability and flexibility for the programmer over other considerations such as raw performance. It natively supports deterministic concurrency and multiple, simultaneous, dynamic control rates. Another key feature is the ability to live code; adding, removing, and modifying code on the fly, while the program is running, without stopping or restarting. It has a highly precise timing/concurrency model, allowing for arbitrarily fine granularity. It offers composers and researchers a powerful and flexible programming tool for building and experimenting with complex audio synthesis programs, and real-time interactive control*
