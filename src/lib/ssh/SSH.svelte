<script>
    import powershell from "$lib/ssh/powershell.png";
</script>
<svelte:head>
    <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.5.1/github-markdown-dark.min.css"
        integrity="sha512-MmL2FuLmm/UH05Ah4JiJwA+G7OCceZDpzGHWqsju4Espzq+9nwQJdQVMNZPd1FNK2H3qDYXdET7HNG7Qm93FEg=="
        crossorigin="anonymous"
        referrerpolicy="no-referrer"
    />
</svelte:head>

<div>
    <h1 class="title is-2">
        <span><a href="#"> # </a></span>SSH Guide
    </h1>
    <div class="container markdown-body">
     <p>In diesem Guide werdet ihr lernen, wie ihr SSH auf euer Maschiene einrichtet, so dass ihr euch auf die <strong>Rechnerhalle</strong> verbinden könnt. </p>
<h1 id="übersicht">Übersicht</h1>
<ul>
<li><a href="#%C3%BCbersicht">Übersicht</a></li>
<li><a href="#rbg-account--ito-account">RBG-Account / ITO-Account</a></li>
<li><a href="#ssh-installieren">SSH installieren</a></li>
<li><a href="#ssh">SSH</a></li>
<li><a href="#ssh-ohne-passwort">SSH ohne Passwort</a></li>
<li><a href="#ssh-config">SSH Config</a></li>
<li><a href="#ssh_dispatch_run_fatal-fehler-auf-windows">ssh_dispatch_run_fatal</a></li>
</ul>
<h1 id="rbg-account--ito-account">RBG-Account / ITO-Account</h1>
<p>Damit du die Rechnerhalle verwenden kannst, brauchst du einen <strong>RBG- / ITO-Account</strong>. Zu beginn des ersten Semesters habt solltest du eine Email bekommen, in dem ein Link ist, mit dem du einen <strong>RBG- / ITO-Account</strong> erstellen kann.
Bei Fragen und Unklarheiten kann man im offizielles <a href="https://www.cit.tum.de/ito/fuer-studierende/fuer-neue/">ITO-Wiki</a> nachschalgen.</p>
<h1 id="ssh-installieren">SSH installieren</h1>
<p>In diesem Abschnitt wird erklärt, wie man <code>ssh</code> installiert.</p>
<h2 id="windows-wsl">Windows (WSL)</h2>
<p>Aus Erfahrung würde ich allen Windows-Nutzern empfehlen <code>ssh</code> über WSL (Windows Subsystem for Linux) zu nutzen. Man kann <code>ssh</code> auch über Windows nativ benutzen, die Einrichtung ist meiner Meinung nacher aber komplizierter und in der Vergangheit hab ich immer wieder Probleme bei Windows gesehen.</p>
<h3 id="wsl-installieren">WSL installieren</h3>
<p><a href="https://learn.microsoft.com/en-us/windows/wsl/install">Offizielle Microsoft Dokumentation</a>.</p>
<p>Zuerst muss WSL für Windows aktiviert werden. Dafür musst du die <strong>Windows Powershell</strong> oder <strong>Windows-CMD</strong> öffnen und folgenden Befehl ausführen.</p>
<p><img src={powershell} alt="Powershell öffnen"></p>
<pre><code class="language-sh"># In Windows Powershell
&gt; wsl --install -d ubuntu
</code></pre>
<p>Sobald sich eine neue Shell mit Linux öffnet, kannst du weiter dem <a href="#linux"><strong>Linux</strong></a> Guide folgen um <code>ssh</code> zu installieren.</p>
<h2 id="macos">macOS</h2>
<p>Auf den neueren <strong>macOS</strong>-Versionen sollte <code>ssh</code> schon installiert sein. Um zu prüfen ob <code>ssh</code> richtig funktioniert, musst du den <strong>Terminal</strong> öffnen und den folgenden Command ausführen.</p>
<pre><code class="language-sh">&gt; ssh
</code></pre>
<p>Wenn <code>ssh</code> installiert ist, solltest du eine <a href="#pr%C3%BCfen-ob-ssh-installiet-ist"><strong>usage</strong>-Message</a> bekommen wie sie weiter unten zu sehen ist.</p>
<h2 id="linux">Linux</h2>
<p><code>ssh</code> ist auf den meißten Linux-Distros (auf WSL auch) schon standartmäßig installiert. Sollte das nicht so sein kannst du den folgenden Schritten folgen um <code>openssh-client</code> für dein Distro zu installieren.</p>
<h3 id="ubuntu-and-wsl">Ubuntu (and WSL)</h3>
<pre><code class="language-sh">&gt; sudo apt update  # updates the mirrors 
&gt; sudo apt openssh-client  # install the ssh-client
</code></pre>
<h3 id="arch-based-manjaro-endeavour-">Arch-based (Manjaro, Endeavour, ...)</h3>
<pre><code class="language-sh">&gt; sudo pacman -Syu  # updates the mirrors 
&gt; sudo pacman -S openssh-client  # install the ssh-client
</code></pre>
<h3 id="prüfen-ob-ssh-installiet-ist">Prüfen ob SSH installiet ist</h3>
<pre><code class="language-sh">&gt; ssh
</code></pre>
<p>Falls <code>ssh</code> korrekt installiert wurde solltest du eine <strong>usage</strong>-Message bekommen.</p>
<pre><code class="language-sh">usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface] [-b bind_address]
           [-c cipher_spec] [-D [bind_address:]port] [-E log_file]
           [-e escape_char] [-F configfile] [-I pkcs11] [-i identity_file]
           [-J destination] [-L address] [-l login_name] [-m mac_spec]
           [-O ctl_cmd] [-o option] [-P tag] [-p port] [-R address]
           [-S ctl_path] [-W host:port] [-w local_tun[:remote_tun]]
           destination [command [argument ...]]
       ssh [-Q query_option]
</code></pre>
<h1 id="ssh">SSH</h1>
<p>Ist jetzt <code>ssh</code> erfolgreich installiert kannst du mit dem folgenden Befehl auf die <strong>Rechnerhalle</strong> verbinden.</p>
<p>Allerdins musst du hierbei immer noch euer <strong>Passwort</strong> eingeben.</p>
<h3 id="auf-die-rechnerhalle-verbinden">Auf die Rechnerhalle verbinden</h3>
<pre><code class="language-sh">&gt; ssh &lt;ito-username&gt;@lxhalle.in.tum.de
# Example:
&gt; ssh muster@lxhalle.in.tum.de
</code></pre>
<h3 id="rechnerhalle-verlassen">Rechnerhalle verlassen</h3>
<ol>
<li>Terminal / Fenster Schlißen</li>
<li><code>exit</code>-Befehl ausführen</li>
</ol>
<pre><code>&gt; exit
</code></pre>
<h1 id="ssh-ohne-passwort">SSH ohne Passwort</h1>
<h3 id="warum-sollte-man-einen-ssh-schlüssel-verwenden">Warum sollte man einen SSH-Schlüssel verwenden?</h3>
<p>Wie du warscheinlich schon bemerkt hast, muss du jedes mal dein <strong>Passwort</strong> eingeben, wenn du versuchst dich, per <code>ssh</code>auf die Rechnerhalle zu verbinden.
Das kann irgendwann nervig werden, vorallem wenn man mehrere Verbindungen zu dem Server gleichzeitig hat.</p>
<p>Hierfür gibt ein eine praktische Lösung. Man kann sich ein <strong>SSH-Key-Paar</strong> erstellen, wovon man den <strong>Öffentlichen Schlüssel</strong> an die Rechnerhalle schickt. </p>
<p>Verbindest du dich nun auf die Rechnerhalle  wird jedes mal dein <strong>lokaler, geheimer Schlüssel</strong> mit dem <strong>öffentlichen Schlüssel auf der Rechnerhalle</strong> abgeglichen. </p>
<p>Wenn alles stimmt kannst du dich sofort verbinden, <strong>ohne dein Passwort eingeben zu müssen</strong>.</p>
<p>Falls du mehr dazu lesen willst is <a href="https://www.ssh.com/academy/ssh/public-key-authentication">hier</a> ein iformativer Link.</p>
<h3 id="ein-ssh-schlüssel-paar-erstellen">Ein SSH-Schlüssel-Paar erstellen</h3>
<blockquote>
<p><strong>Hinweise</strong>: Alle folgenden Befehle müssen auf eurem <strong>eigenen Computer</strong> ausgeführt werden, <strong>NICHT auf der Rechnerhalle</strong>. Ihr könnt die rechneralle mit <code>exit</code> verlassen</p>
</blockquote>
<p><strong>1. SSH-Schlüssel-Paar erstellen</strong></p>
<pre><code class="language-sh">&gt; ssh-keygen -t ed25519
</code></pre>
<p><strong>2. Dateinamen unverändern lassen (<code>&lt;Enter&gt;</code> drücken)</strong></p>
<pre><code class="language-sh">Generating public/private ed25519 key pair.
Enter file in which to save the key (path/to/home/.ssh/id_ed25519):  # &lt;Enter&gt;
</code></pre>
<p><strong>3. Kein Passwort eingeben</strong></p>
<p>Im nächsten Schritt werdet ihr nach einen <strong>Passwort</strong> gefragt. Hier müsst ihr kein Passwort eingeben sondern einfach nur <code>&lt;Enter&gt;</code>. Solltet ihr doch ein Passwort eingeben müsst ihr dieses Passwort eingeben, jedes mal wenn ihr den <strong>SSH-Schlüssel</strong> verwendet.</p>
<pre><code class="language-sh"># Hier kein Passwort eingeben, nur &lt;Enter&gt; drücken
Enter passphrase (empty for no passphrase):  # &lt;Enter&gt;
Enter same passphrase again:                 # &lt;Enter&gt;
</code></pre>
<p><strong>4. Geheimer und Öffnetlicher Schlüssel</strong></p>
<p>Falls ihr den Schritten korrekt gefolgt seid, solltet ihr in <code>~/.ssh</code> zwei neue Dateien finden.</p>
<pre><code class="language-sh">&gt; ls -l ~/.ssh
-rw------- 1 user user  411 13. Jan 13:05 id_ed25519        # geheimer Schlüssel
-rw-r--r-- 1 user user  102 13. Jan 13:05 id_ed25519.pub    # öffentlicher Schlüssel
</code></pre>
<h3 id="öffentlichen-schlüssel-an-die-rechnerhalle-schicken">Öffentlichen Schlüssel an die Rechnerhalle schicken</h3>
<pre><code class="language-sh">&gt; ssh-copy-id -i ~/.ssh/id_ed25519.pub &lt;ito-username&gt;@lxhalle.in.tum.de 
# Example: ssh-copy-id -i ~/.ssh/id_ed25519.pub muster@lxhalle.in.tum.de
</code></pre>
<h3 id="auf-die-rechnerhalle-zugreifen">Auf die Rechnerhalle zugreifen</h3>
<p>Falls allen Schritten erfolgreich gefolgt wurden, kannst du jetzt mit dem selben Befehl wie vorher auf die Rechnerhalle zu greifen. Jetzt aber ohne ein Passwort einzugeben.</p>
<pre><code class="language-sh">&gt; ssh &lt;ito-username&gt;@lxhalle.in.tum.de
# Example: ssh muster@lxhalle.in.tum.de
</code></pre>
<h1 id="ssh-config">SSH Config</h1>
<p>Anstelle jedes mal <code>ssh muster@lxhalle.in.tum.de</code> eingeben müssen, kannst du auch eine SSH-Config-Datei erstellen. In der SSH-Config kannst du Konfigurationen für verschiedene SSH-Server speichern. </p>
<h4 id="beispiel">Beispiel</h4>
<pre><code class="language-sh">&gt; ssh rechnerhalle                  # (die coole Art)
# anstelle
&gt; ssh muster@lxhalle.in.tum.de      # (die nicht so coole Art)
</code></pre>
<h3 id="1-config-datei-erstellen">1. Config Datei erstellen</h3>
<p>Zuerst musst du <strong>auf deinem Laptop</strong> (nicht Rechnerhalle!) eine Datei, namens <code>config</code> in dem <code>~/.ssh</code> Directory, erstellen.</p>
<p>Der folgende Befehl erstellt diese Datei.</p>
<pre><code class="language-sh">&gt; touch ~/.ssh/config       # erstellt einen file namen config im ~/.ssh Ordner
</code></pre>
<h3 id="2-config-öffnen">2. Config öffnen</h3>
<p>Nun musst du die neu, erstellte Datei öffnen und editieren. Mit dem folgenden Befehl könnt ihr die Datei in dem <code>nano</code>-Editor öffnen.</p>
<pre><code class="language-sh">&gt; nano ~/.ssh/config
</code></pre>
<p>Sobald die Datei geöffnet ist, kannst du anfangen in der (noch leeren) Datei mit den <strong>Pfeiltasten</strong> rumnavigieren und anfange die Config zu beschreiben.</p>
<h3 id="3-config-editieren">3. Config editieren</h3>
<pre><code class="language-sh"># in der ~/.ssh/config Datei

Host custom-name-für-den-server
    HostName lxhalle.in.tum.de
    User dein-ito-username


# Beispiel
Host rechnerhalle
    HostName lxhalle.in.tum.de
    User muster
</code></pre>
<h3 id="4-config-datei-speichern">4. Config Datei speichern</h3>
<p>Um das geschriebene in <code>nano</code> zu speichern, musst du <code>strg+x</code> drücken.
Von da aus, musst du den Anweisungen des Editors folgen um die Datei zu speichern</p>
<h3 id="5-profit">5. Profit!</h3>
<p>Wenn du jetzt alles funktioniert hat, kannst du deine neue SSH-Config ausprobieren</p>
<pre><code class="language-sh">&gt; ssh custom-name-für-den-server 
</code></pre>
<h1 id="ssh_dispatch_run_fatal-fehler-auf-windows">ssh_dispatch_run_fatal</h1>
<p>Manche Windows-Nutzer bekommen den folgenden Fehler, wenn sie versuchen SSH verwenden.</p>
<pre><code class="language-sh">ssh_dispatch_run_fatal: Connection to 131.159.76.9 port 22: message authentication code incorrect
</code></pre>
<p>Um das Problem zu beheben, brauchst du erst mal eine <a href="#ssh-config">SSH Config</a>.</p>
<p>Sobald du eine SSH-Config hast kannst du die folgende Zeile in deine <code>rechnerhallen</code>-Konfiguration einfügen.</p>
<pre><code class="language-sh">Host custom-name-für-den-server
  HostName lxhalle.in.tum.de
  MACs hmac-sha2-512            # Der Fix
  User ito-username
</code></pre>
<p>Danke an <a href="https://home.in.tum.de/~arb/">Danial Arbabi</a> (cooler GRA Tutor) dafür.</p>

 
    </div>
</div>
<style>
    .markdown-body {
        box-sizing: border-box;
        min-width: 200px;
        max-width: 980px;
        margin: 0 auto;
        padding: 45px;
        background-color: #14161a;
    }

    @media (max-width: 767px) {
        .markdown-body {
            padding: 15px;
        }
    }
    code {
        white-space: pre-line;
    }
</style>
