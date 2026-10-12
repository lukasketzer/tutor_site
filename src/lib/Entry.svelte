<script>
    import Button from "$lib/Button.svelte"
    export let week; 
    export let files;
    if (files == undefined) {
        files = []
    }

</script>



<div class="box" style="width: 70%">

    <h2 class="title is-size-5-mobile">Woche {week}</h2>
    <hr>

    {#each files as file}
        <Button url={file.url} text={file.text} />
    {/each}

</div>
