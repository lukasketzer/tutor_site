<script>
    import Entries from "$lib/lukas/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
</script>

<svelte:head>
    <title>GRA SS24</title>
</svelte:head>

<div class="container">
    <Header name={"Lukas Ketzer"}/>

    <Navbar is_active={0}/>
    

    <Entries />
</div>

