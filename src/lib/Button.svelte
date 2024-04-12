<svelte:head>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</svelte:head>
<script>
    export let url;
    export let text;
    const pdf_icon = `<i class="bi bi-file-earmark-pdf"></i>`
    const zip_icon = `<i class="bi bi-file-earmark-zip"></i>`;
    const download_icon = `<i class="bi bi-download"></i>`;
    const code_icon = `<i class="bi bi-code-slash"></i>` 
    let icon = download_icon;

    if (url.includes(".pdf")) {
        icon = pdf_icon;
    } else if (url.includes(".zip")) {
        icon = zip_icon;
    } else if (url.includes(".c")) {
        icon = code_icon;
    }
</script>

<a href={url} class="button is-outlined is-primary is-rounded is-inverted block" download>
    <span class="icon-text is-size-6-mobile">
        <span class="icon">{@html icon}</span>  
        <span>{text}</span>
    </span>
</a>

<style>
    @import url("https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css");

    .icon{
        padding-bottom: 6px;
    }
    .icon-text {
        font-size: large;
    }

    
</style>
