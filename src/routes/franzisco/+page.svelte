<script>
    import Entries from "$lib/franzisco/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
</script>


<div class="container">
    <Header name={"Franzisco Shit"}/>

    <Navbar is_active={1}/>
    

    <Entries />
</div>