<script>
    import Entries from "$lib/franzisco/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
</script>


<div class="container">
    <Header name={"Franzisco Shit"}/>
    <Links email={"lukas.a.ketzer@tum.de"} github_link={"https://github.com/lukasketzer"} zulip={"Lukas Ketzer"}/>

    <Navbar is_active={1}/>
    

    <Entries />
</div>