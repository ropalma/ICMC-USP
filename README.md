# Sharing my references of study

## English

- [Mairo Vergara](http://www.mairovergara.com/)
- [Anki](https://apps.ankiweb.net/)
- [Grammarly](https://www.grammarly.com/)

## Roadmap Software Engineering

- [Coding Interview University](https://github.com/jwasham/coding-interview-university)
- [Teach Yourself CS](https://teachyourselfcs.com/)
- [wiki.icmc.usp.br](http://wiki.icmc.usp.br/index.php/P%C3%A1gina_principal_CoteiaWIKI)

## Algorithms and Data Structs

 - Most Recommended Book
    - [Algoritmos Teoria e Prática - Thomas H. Cormen](https://www.amazon.com.br/Algoritmos-Teoria-Pr%C3%A1tica-Thomas-Cormen/dp/8535236996)
 - YouTube
    - [Linguagem C Programação Descomplicada](https://www.youtube.com/user/progdescomplicada/videos) :skull:
 - Sites
    - [GeeksForGeeks](https://www.geeksforgeeks.org/)
    - [AssemblyProgressivo.net](https://www.assemblyprogressivo.net/)
    - [MIT Scratch](https://scratch.mit.edu/projects/editor/)
- Code Training
    - [Project Euler](https://projecteuler.net/)
    - [HackerRank](https://www.hackerrank.com/)
    - [Edabit](https://edabit.com)
    - [URI Online Judge](https://www.urionlinejudge.com.br/judge/en/login)
- KhanAcademy
   - [Computer Science](https://www.khanacademy.org/computing/computer-science)
   - [Notação assintótica](https://pt.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/asymptotic-notation)
- Recursion :skull:
   - [O que é recursão? Teste de Mesa com Fatorial - Softblue](https://www.youtube.com/watch?v=V60g61dhKmg)
- Data Structs Visualization
   - [VisualGo](https://visualgo.net/en)
   - [University of San Francisco - CS](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
- Big O
   - [A beginner's guide to Big O notation](https://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/)
   - [A coffee-break introduction to time complexity of algorithms](https://dev.to/vickylai/a-coffee-break-introduction-to-time-complexity-of-algorithms-160m?utm_source=digest_mailer&utm_medium=email&utm_campaign=digest_email)
   - O(1) Constant Time
      - Best Case Possible
      - If an algorithm has a constant time, it means that it always takes the same amount time to produce the output.
      - Example: array.pop()
   - Logarithms O(log n)
      - Preferible in most of times
      - Logarithms are the inverse of exponentiation.
      - Example: Classic Binary search algorithm -> divide-to-conquer
      - <img src="ologn.png" alt="ologn">
   - Linear time O(n)
      - Preferible in most of times
      - If an algorithm has a linear time, it means that the running time of an algorithm grows as the input size grows.
      - Example: array.forEach() sum all values
   - Linear Logarithms O(n log n)
      - Acceptable
      ```
      x = n
      while ( x > 0 ) {
        y = x
        while ( y > 0 ) {
           y = y / 2
        }
        x = x - 1
      }
      ```
      - Example: classic merge sort -> divide-to-conquer
   - Quadratic time O(n²) :skull:
      - Nice To Avoid
      - The running time of an algorithm is directly proportional to the square of the size of the input.
      - Example: sum of matrizes
      ```
      for (var outer = 0; outer < elements.Count; outer++){
        for (var inner = 0; inner < elements.Count; inner++){
          ...
        }
      }
      ```
   - Exponential Time O(2^n) :skull: :skull:
      - Worst Case Possible, always try to avoid
      - Denotes an algorithm whose growth doubles with each additon to the input data set. The growth curve of an O(2N) function is exponential - starting off very shallow, then rising meteorically
      - Example: recursive calculation of Fibonacci numbers
      ```
      int Fibonacci(int number){
          if (number <= 1) return number;
          return Fibonacci(number - 2) + Fibonacci(number - 1);
      }
      ```
  
## [Unix](https://pt.wikipedia.org/wiki/Unix)

 - [Linux](https://www.linuxfoundation.org/)
    - Sites
       - [Guia Foca](http://www.guiafoca.org/?page_id=51)
       - [SS64 - Commands CLI References](https://ss64.com/)
       - [Kernel.org](https://www.kernel.org/)
    - Apps
       - [Linux Command Library](https://play.google.com/store/apps/details?id=com.inspiredandroid.linuxcommandbibliotheca&hl=en&rdid=com.inspiredandroid.linuxcommandbibliotheca)
    - YoTube
       - [Diolinux](https://www.youtube.com/user/Diolinux)
       - [Toca do Tux](https://www.youtube.com/channel/UCkATW9o8m4pnXAAmac2o63Q)
       - [Curso de Linux Básico / Certificação LPIC1](https://www.youtube.com/watch?v=u16ZDPcf8Rc&list=PLucm8g_ezqNp92MmkF9p_cj4yhT-fCTl7)
    - Tools
       - [VirtualBox](https://www.virtualbox.org/wiki/Downloads)
       - [Etcher - Flash OS images to SD cards & USB drives](https://etcher.io/)
       - [Rufus.ie for Windows](https://rufus.ie)
       - [WineHQ](https://www.winehq.org/)
       - [Vim Para Noobs](https://woliveiras.com.br/vimparanoobs/)
       - [Lutris.net :video_game:](https://lutris.net/)
       - [$ sudo apt install zsnes :video_game:](http://www.zsnes.com/)
       - [$ sudo apt install playonlinux :video_game:](https://www.playonlinux.com/en/)
    - Operation System
       - [Lubuntu - OS I Use and Recommend. Simple, Light and Usefull](https://lubuntu.net/)
 - FreeBSD
    - Sites
       - [Documentation PT-BR](https://www.freebsd.org/doc/pt_BR.ISO8859-1/)
    - Books
       - [FreeBSD: O Poder dos Servidores em Suas Mãos - 2 Edição](https://www.amazon.com.br/FreeBSD-Poder-Servidores-Suas-M%C3%A3os-ebook/dp/B00FFZOE8Y)

## Windows

 - Sites
    - [Baboo](https://www.baboo.com.br/)
 - Tools
    - [Cmder](http://cmder.net/)

## Security 

 - Sites
    - [OWASP](https://www.owasp.org/index.php/Main_Page)
    - [EUGDPR.org](https://eugdpr.org/)
    - [LGPD - Lei Geral de Proteção de Dados Pessoais](http://www.planalto.gov.br/ccivil_03/_Ato2015-2018/2018/Lei/L13709.htm)
    - [Livro - Fundamentos de Engenharia Reversa - Mente Binária](https://mentebinaria.gitbook.io/engenharia-reversa/antes-de-comecar)
    - [Forum CaveiraTech](https://caveiratech.com/forum/)
 - YouTube
    - [Gabriel Pato](https://www.youtube.com/channel/UC70YG2WHVxlOJRng4v-CIFQ)
    - [CaveiraTech](https://www.youtube.com/user/caveiratech2/playlists)
    - [Curso de Engenharia Reversa Online - Papo Binário](https://www.youtube.com/watch?v=IkUfXfnnKH4&list=PLIfZMtpPYFP6zLKlnyAeWY1I85VpyshAA)
 - Courses 
    - [Fundamentos de Ethical Hacking - Udemy](https://www.udemy.com/fundamentos-de-ethical-hacking/learn/v4/)
    - [Solyd](https://solyd.com.br)
    - [Técnicas de Invasão](https://tecnicasdeinvasao.com/)
    - [Desenvolimento de Software Seguro - Curso Online Gratuito - ICA Instituto ](https://desenvolvimentoseguro.icainstituto.com.br/)
 - [DAT Protocol](https://www.datprotocol.com/)
    - [DatProject.org](https://datproject.org)
    - [Try Dat](https://try-dat.com/)
 - Database
    - World's fastest password cracker
       - [HashCat](https://hashcat.net/hashcat/)
    - Recommended Data Encryption
       - [Argon2](https://github.com/P-H-C/phc-winner-argon2)
       - [PBKDF2](https://en.wikipedia.org/wiki/PBKDF2)
       - [Scrypt](https://en.wikipedia.org/wiki/Scrypt)
       - [BCrypt](https://en.wikipedia.org/wiki/Bcrypt)
    - NOT RECOMMENDED
       - [MD5](https://pt.wikipedia.org/wiki/MD5)
       - [SHA1~2~256](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
 - Tools
    - Virtual Machines for Pentest
       - [PentesterLab](https://www.pentesterlab.com/exercises/)
       - [PentestBox](pentestbox.org)
          - [tools.pentestbox.org](https://tools.pentestbox.org/)
    - Transport Layer Security/Secure Sockets Layer
       - [Let's Encrypt](https://letsencrypt.org/)
    - Software
       - [WireShark](https://www.wireshark.org/)
       - [Exploit-DB](https://www.exploit-db.com/)
       - [metasploit](https://www.metasploit.com/)
       - [SQLMap](http://sqlmap.org/)
       - [$ nmap galhardoo.com](https://nmap.org/)
       - [$ traceroute galhardoo.com](https://www.lifewire.com/traceroute-linux-command-4092586)
       - [$ curl galhardoo.com](https://curl.haxx.se/)
       - [$ whafw00f galhardoo.com](https://github.com/EnableSecurity/wafw00f)
       - [$ ping galhardoo.com](https://www.wikiwand.com/en/Ping)
       - [$ host galhardoo.com](https://www.computerhope.com/unix/host.htm)
       - [$ whois galhardoo.com](https://who.is/)
       - [DuckDuckGo](https://duckduckgo.com)
       - [Bernes Lee Solid](https://solid.mit.edu/)
       - [Beaker Browser](https://beakerbrowser.com)
       - [TorProject](https://www.torproject.org/)
          - [TheHiddenWiki](https://thehiddenwiki.org/)
          
## Functional Programming

- [Aprender Haskell será um grande bem para você](http://haskell.tailorfontela.com.br/)

## Open Source
 
 - Sites
    - [OpenSource.org](https://opensource.org/)
    - [OpenSource.Guide](https://opensource.guide/)
    - [Creative Commons](https://creativecommons.org/)
    - [Scrum Poker Online](https://scrumpoker.online/)
 - Software
    - [ERP - SigeLite](https://www.sigelite.com.br/)
    - [Audio - Audacity](https://www.audacityteam.org/)

## Online Courses

- [Udemy - Courses I'm enrolled](https://www.udemy.com/user/alex-galhardo-vieira/)
- [Coursera - Learning How to Learn: Powerful Mental Tools to Help You Master Tough Subjects](https://www.coursera.org/learn/learning-how-to-learn)

## Blogs

- [Medium - A LOT](https://medium.com/)
- [Quora - A LOT](https://quora.com/)
- [Akita on Rails - A LOT](http://www.akitaonrails.com/)
- [Reddit - A LOT](https://www.reddit.com)
- [Hacker News](https://news.ycombinator.com/)
- [Stalt](https://staltz.com/)
- [JornadaPeloConhecimento](https://medium.com/petrobras)
- [Joel Spolsky OnSoftware](https://www.joelonsoftware.com/)
- [WaitButWhy](https://waitbutwhy.com/)
- [ThinkWithGoogle](https://www.thinkwithgoogle.com/)
- [Hacks Mozilla](https://hacks.mozilla.org/)
- [Willian Justen](https://willianjusten.com.br/)
- [Felipe Fialho](https://www.felipefialho.com/)
- [Luiz Tools](http://www.luiztools.com.br/)
- [Henrique Bastos](https://henriquebastos.net)
- [RockSeat](https://rocketseat.com.br/) 
- [Umbler Blog](https://blog.umbler.com)
- [InfoQ](https://www.infoq.com/)
- [WBruno](http://wbruno.com.br/)
- [Nateliason](https://www.nateliason.com)
- [RamonSilva](http://ramonsilva.net/)
- [O Futuro Das Coisas](https://ofuturodascoisas.com/)
- [Filipe Deschamps](https://www.filipedeschamps.com.br/)
- [BugginhoAcademy](https://bugginhoacademy.com.br/blog/)
- [Gabs Ferreira](http://gabsferreira.com/)
- [Jaydson Gomes](https://jaydson.com/)
- [Phil Calcado](http://philcalcado.com/)
- [VidaDeSuporte](https://vidadesuporte.com.br/)
- [TiagoGouvea](https://www.tiagogouvea.com.br/)
- [VidaDeProgramador](https://vidadeprogramador.com.br/)
- [ProfissionaisTI](https://www.profissionaisti.com.br/)

## Nice Articles

 - [O que é propósito de vida](https://mopora.com/artigos/o-que-e-proposito-de-vida/)
 - [The Invented History of 'The Factory Model of Education'](http://hackeducation.com/2015/04/25/factory-model)
 - [The Humble Programmer by Edsger W. Dijkstra](https://www.cs.utexas.edu/~EWD/transcriptions/EWD03xx/EWD340.html)
 - [Teach Yourself Programming in Ten Years - Peter Norvig](http://norvig.com/21-days.html)
 - [Getting Real - the smarter, faster, easy way to build a sucesfull web application - BaseCamp](https://basecamp.com/books/getting-real)
 - [Principles for Success - Ray Dalio](https://www.principles.com/principles-for-success/)
 - [The Twelve Factor App](https://12factor.net/)
 - [Write Code Every Day - John Resig](https://johnresig.com/blog/write-code-every-day/)
 - [Why Good Programmers Are Lazy and Dumb](http://blogoscoped.com/archive/2005-08-24-n14.html)
 - [The Feynman Technique: The Best Way to Learn Anything - Easy to Understand | Hard To Master](https://fs.blog/2012/04/learn-anything-faster-with-the-feynman-technique/)
 - [WaitButWhy - The Cook and the Chef: Musk’s Secret Sauce - Easy to Understand | Hard to Master](https://waitbutwhy.com/2015/11/the-cook-and-the-chef-musks-secret-sauce.html)
 - [Rob Pike's 5 Rules of Programming](http://users.ece.utexas.edu/~adnan/pike.html)
 - [The Ten Commandments of Egoless Programming](https://blog.codinghorror.com/the-ten-commandments-of-egoless-programming/)
 - [What makes a good programmer?](http://www.techfounder.net/2009/07/22/what-makes-a-good-programmer/?subscribe=error#509)
 - [Self-Education: Teach Yourself Anything with the Sandbox Method](https://www.nateliason.com/blog/self-education)

## Communities

- [BrazilJS](https://braziljs.org/)
- [FrontEnd Br](https://github.com/frontendbr)
- [Training Center](https://github.com/training-center)
- [BackEnd Br](https://github.com/backend-br)
- [Comunidades Web](https://github.com/brasil-php/comunidades)
- [NodeJS Brasil - Facebook](https://www.facebook.com/groups/nodejsbrasil/about/)
- [Dev Translate](https://github.com/devtranslate)
- [CodamosClub](https://www.codamos.club/)
- [HashNode](https://hashnode.com/)
- [Mulheres na Computação](https://mulheresnacomputacao.com/)
- [Dev Newsletters](https://devnewsletters.github.io/)

## Podcasts

 - Technology & Arts & Games & Science 
    - Portuguese
       - [Dev Na Estrada](https://devnaestrada.com.br/)
       - [HipsterTech](https://hipsters.tech/)
       - [NerdTech](https://www.alura.com.br/podcast-nerdtech)
       - [LoopMatinal](http://www.loopmatinal.com/)
       - [Syntax](https://syntax.fm/)
       - [DataBase Cast](http://databasecast.com.br/wp/)
       - [Podprogramar](https://mundopodcast.com.br/podprogramar/)
       - [SudoCast](https://github.com/sudocast)
       - [OneBitCode](https://onebitcode.com/category/podcast/)
       - [QuebraDev](http://quebradev.com.br/)
       - [Zofe](https://zofe.com.br/)
       - [ElementCast](https://elemencast.github.io/#/episodios/6)
       - [Egermano](https://anchor.fm/egermano)
       - [Revolution](https://www.youtube.com/channel/UCRmG9ZyWxUenzxfoyatqp3A)
       - [SciCast](http://www.deviante.com.br/podcasts/scicast/)
       - [MeiaLua](http://www.deviante.com.br/podcasts/meialua/)
       - [Miçangas](http://www.deviante.com.br/podcasts/micangas/)
       - [TecnoCast](https://tecnoblog.net/categoria/podcast/)
       - [TricoTech](http://www.trico-tech.com/)
       - [GGDevCast](https://ggdevcast.com.br/)
       - [Por Trás dos Controles](https://www.radio.ufscar.br/shows/por-tras-dos-controles/)
       - [PixelsInk](https://www.cgmagonline.com/media/podcasts/pixels-ink/)
       - [DragoesDeGaragem](http://dragoesdegaragem.com/)
       - [Reloading](http://reloading.com.br/)
       - [RPGGuaxa](http://www.deviante.com.br/podcasts/rpguaxa/)
    - English
       - [CodeNewbie](https://www.codenewbie.org/)
       - [ShopTalk Show](https://shoptalkshow.com/)
       - [Learn To Code With Me](https://learntocodewith.me/podcast/)
       - [DeveloperTea](https://spec.fm/podcasts/developer-tea)
       - [Indie Hackers Podcast](https://www.indiehackers.com/podcast)
       - [FreeCodeCamp](https://freecodecamp.libsyn.com/)
       - [This Developers Life](http://thisdeveloperslife.com)
       - [CodingBlocks](https://www.codingblocks.net/)
       - [Changelog](https://changelog.com/podcast)
       - [FZDPodcast](http://fzdpodcast.com/)
       - [Programming Throwdown](https://www.programmingthrowdown.com/)
       - [Software Engineering Radio](http://www.se-radio.net/)
       - [GeekSpeak](https://geekspeak.org/)
       - [DevChat.TV](https://devchat.tv/)
       - [JavaScript Jabber](https://devchat.tv/js-jabber/)
       - [FullStack Radio](http://www.fullstackradio.com/)
       - [Twit.TV](https://www.twit.tv/)
       - [This Week In Tech](https://www.twit.tv/shows/this-week-in-tech)
       - [Security Now](https://www.twit.tv/shows/security-now)
       - [Floss Weekly](https://www.twit.tv/shows/floss-weekly)
       - [The Knowledge Project](https://fs.blog/the-knowledge-project/)
 - Entrepreneurship & Others
    - Portuguese
       - [GVCast](https://geracaodevalor.com/gvcast/)
       - [Heroes 12 minutos](https://soundcloud.com/heroes-12min-podcast)
       - [Like a Boss](https://www.likeaboss.com.br/)
       - [Decrepitos](https://decrepitos.com/)
       - [GunCast](https://blog.keeplearning.school/guncast)
       - [NerdCast](https://jovemnerd.com.br/nerdcast)
       - [PapriCast](http://paprica.org/categoria/papricast/)
       - [B9 Podcasts](https://www.b9.com.br/podcasts/)
       - [ResumoCast](https://www.resumocast.com.br/)
       - [AntiCast](http://anticast.com.br/)
       - [ChutandoAEscada](https://chutandoaescada.com.br/)
       - [DicasCurtas](https://dicascurtas.com.br/)
       - [EscribaCafe](https://escribacafe.com/tagged/podcast)
    - English
       - [Tim Ferris Podcast](https://tim.blog/podcast/)
       - [Masters Of Scale](https://mastersofscale.com/)
       - [Rework.FM](https://rework.fm/)
       - [MadeYouThinkPodcast](https://madeyouthinkpodcast.com/)

## YouTube #StopWatchingTV

 - Technology
    - [Curso em Video](https://www.youtube.com/user/cursosemvideo)
    - [Fábrica de Noobs](https://www.youtube.com/channel/UCGObNjkNjo1OUPLlm8BTb3A)
    - [COD3R CURSOS](https://www.youtube.com/channel/UCcMcmtNSSQECjKsJA1XH5MQ/featured)
    - [CodigoFonte TV](https://www.youtube.com/user/codigofontetv)
    - [BrasilJS](https://www.youtube.com/user/BrazilJS)
    - [EstudoNauta](https://www.youtube.com/channel/UCJcWQ9MgPlHIFMx8uDWEYNg)
    - [FreeCodeCamp](https://www.youtube.com/channel/UC8butISFwT-Wl7EV0hUK0BQ)
    - [Papo Binário](https://www.youtube.com/channel/UCuQ8zW9VmVyml7KytSqJDzg)
    - [Baboo](https://www.youtube.com/user/baboo/videos)
    - [CodellabCode](https://www.youtube.com/channel/UCVheRLgrk7bOAByaQ0IVolg)
    - [CanalTech](https://www.youtube.com/user/canaltechbr)
    - [William Oliveira](https://www.youtube.com/channel/UCWrqsnPLl6aRX0ECUmPaZEw)
    - [UNIVESPTV](https://www.youtube.com/user/univesptv/playlists)
    - [Engenharia Reversa](https://www.youtube.com/channel/UCagV1LuB6C52fFtZwVywZYg)
    - [DevNaEstrada](https://www.youtube.com/channel/UCtIygB7LtILSFWR0kxtZC-A/videos)
    - [RocketSeat](https://www.youtube.com/channel/UCSfwM5u0Kce6Cce8_S72olg/videos)
    - [Bóson Treinamentos](https://www.youtube.com/user/bosontreinamentos)
    - [ProgramadorBR](https://www.youtube.com/channel/UCrdgeUeCll2QKmqmihIgKBQ)
    - [Laboratório da Júlia](https://www.youtube.com/channel/UChfu9xWITOvsXYLKm7hieSQ)
    - [Rodrigo Souza](https://www.youtube.com/channel/UCdHcO3zYXVco91CIAk1u4PA)
    - [SoftBlue](https://www.youtube.com/user/softbluecursos)
    - [CS50](https://www.youtube.com/user/cs50tv/videos)
    - [Computherpile](https://www.youtube.com/user/Computerphile)
    - [A história da Tecnologia - TecMundo](https://www.youtube.com/playlist?list=PL7cCKVGMzqmbyaouQulXxUJLdwW4qBMpp)
    - [Mayuko](https://www.youtube.com/user/hellomayuko/videos)
    - [Computer Science - CrashCourse](https://www.youtube.com/watch?v=tpIctyqH29Q&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo)
 - Talks
    - [Alura Cursos Online](https://www.youtube.com/user/aluracursosonline/videos)
    - [Tedx Talks](https://www.youtube.com/channel/UCsT0YIqwnpJCM-mx7-gSA4Q)
    - [iMasters](https://www.youtube.com/user/imasters)
    - [InfoQ Brasil](https://www.youtube.com/channel/UCjiSYWQhLi9a4znW2h5pCrg)
    - [Campus Party](https://www.youtube.com/channel/UCUendDl_o6qhA7GtHxH3PTA)
    - [Futuro Descentralizado](https://www.youtube.com/channel/UCwgs6fw_BSDG5MbEivaw05g/videos)
    - [Locaweb](https://www.youtube.com/channel/UCqHIy-SOkAgNU3b-PRUL8qA)
    - [Fabio Akita](https://www.youtube.com/channel/UCib793mnUOhWymCh2VJKplQ)
    - [Pagar.me Talks](https://www.youtube.com/channel/UCNhSCufrcOMeFvzEM7tt9Lw)
    - [Endeavor Brasil](https://www.youtube.com/user/endeavorbrasil/videos)
 - Science
    - [Nerdologia](https://www.youtube.com/channel/UClu474HMt895mVxZdlIHXEA)
    - [SpaceToday](https://www.youtube.com/channel/UC_Fk7hHbl7vv_7K8tYqJd5A)
    - [PeixeBabel](https://www.youtube.com/channel/UCqB90BBr6eNRaJl-kl30Xxw)
    - [TED-Ed](https://www.youtube.com/channel/UCsooa4yRKGN_zEE8iknghZA)
    - [Canal do Pirula](https://www.youtube.com/user/Pirulla25)
    - [Kurzgesagt – In a Nutshell](https://www.youtube.com/user/Kurzgesagt)
    - [Vsauce](https://www.youtube.com/user/Vsauce)
    - [Ponto em Comum](https://www.youtube.com/channel/UCGo3vjM2Ll3XujL-zYT5SMg)
    - [Alimente o Cérebro](https://www.youtube.com/channel/UC3fBS89aQ7mt5G1TodU4HNg)
    - [Singularidade](https://www.youtube.com/channel/UCA6-1g_4e3iuT1qeXe6xNuA/videos)
    - [Minutos Psíquicos](https://www.youtube.com/channel/UCFiEI1kDHlO9UQtxx0wj-XA)
    - [CrashCourse Kids](https://www.youtube.com/user/crashcoursekids/videos)
    - [BigThink](https://www.youtube.com/user/bigthink)
    - [AsapSCIENCE](https://www.youtube.com/channel/UCC552Sd-3nyi_tk2BudLUzA)
    - [Ciência Todo Dia](https://www.youtube.com/user/CienciaTodoDia)
    - [Primata Falante](https://www.youtube.com/user/mrprimatafalante)
    - [Manual do Mundo](https://www.youtube.com/user/iberethenorio) 
    - [Thoughty2](https://www.youtube.com/user/Thoughty2/featured)
    - [MathGurl](https://www.youtube.com/channel/UC5RV_s1Jh-jQI4HfexEIb2Q)
    - [A Matemaníaca por Julia Jaccoud](https://www.youtube.com/channel/UCz4Zuqtj9fokXH68gZJmCdA)
 - Self Development
    - [NeuroVox](https://www.youtube.com/user/NeuroVoxConsultoria)
    - [Moporã](https://www.youtube.com/channel/UCZYCNT6OT4_cgt-ldtwGQJw)
    - [Jordan Peterson](https://www.youtube.com/user/JordanPetersonVideos)
    - [Arata Academy](https://www.youtube.com/channel/UCEdgNBcBybRtwv836C8El4g)
    - [Seja Uma Pessoa Melhor](https://www.youtube.com/channel/UCbG7_Agdb99rhG9-rhY8iTg/videos)
 - Philosophy
    - [Canal do Cortella](https://www.youtube.com/channel/UCyTS929PXJSUiBEFSzdypgg)
    - [Luiz Felipe Pondé](https://www.youtube.com/channel/UCW9jLtlONRp7W-AK9F8M66Q)
    - [Prazer, Karnal](https://www.youtube.com/channel/UC4O2eKb8vI4VlMeNp90asfg)
    - [Saber Filosófico](https://www.youtube.com/channel/UCWdXgfpEIZIGzah9_yCL-Xw)
 - Others
    - [Canal do Moscoso](https://www.youtube.com/channel/UChVeSyoB200ALDpnTr1TOrg/videos)
    - [Canal Nostalgia](https://www.youtube.com/user/fecastanhari)
    - [MuriloGun](https://www.youtube.com/user/murilogun/videos)
    - [Ler Antes de Morrer](https://www.youtube.com/channel/UCTubbc8ei3JfOBbicSJYPfQ)
    - [Metaforando](https://www.youtube.com/channel/UCh7TUTXojlE8vRtb-EnuDzw)
    - [Canal do Por Quê?](https://www.youtube.com/channel/UCqWMwhpW-rggQZtfNXIqkrw)
    - [Meteoro Brasil](https://www.youtube.com/channel/UCk5BcU1rOy6hepflk7_q_Pw)
    

<br><br>

<p align="center">
  "<strong>I am always ready to learn although I do not always like being taught."</strong><br><br> - Winston Churchill
    <br>
  </p>
