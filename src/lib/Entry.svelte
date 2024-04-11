<script>
    import Button from "$lib/Button.svelte"
    export let week; 
    export let files;
    if (files == undefined) {
        files = []
    }

</script>



<div class="box">

    <h1 class="title">Woche {week}</h1>
    <hr>

    {#each files as file}
        <Button url={file.url} text={file.text} class="block"/>
    {/each}

</div>

<style>
    .box {
        width: 70%;
    }

</style>