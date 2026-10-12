<script>
    import Entries from "$lib/lukas/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
    import Seo from "$lib/Seo.svelte";
</script>

<Seo
    title="GRA Tutorium SS24 – Lukas Ketzer | Grundlagen: Rechnerarchitektur TUM"
    description="Folien, Beispielcode und nützliche Links aus dem Tutorium Grundlagen: Rechnerarchitektur (GRA) an der TUM im Sommersemester 2024 bei Lukas Ketzer."
    jsonld={{
        "@context": "https://schema.org",
        "@type": "WebSite",
        name: "GRA Tutorium SS24",
        url: "https://home.cit.tum.de/~ketz/",
        inLanguage: "de",
        author: { "@type": "Person", name: "Lukas Ketzer", sameAs: ["https://github.com/lukasketzer"] },
    }}
/>

<div class="container">
    <Header name={"Lukas Ketzer"} />
    <Links
        email={"lukas.a.ketzer@tum.de"}
        github_link={"https://github.com/lukasketzer"}
        zulip={"https://zulip.in.tum.de/#narrow/dm/11498-Lukas-Ketzer"}
        zulip_name={"Lukas Ketzer"}
    />

    <Navbar is_active={0} />

    <Entries />
</div>
